/*
 * Copyright 2001-2004 Brandon Long
 * All Rights Reserved.
 *
 * ClearSilver Templating System
 *
 * This code is made available under the terms of the ClearSilver License.
 * http://www.clearsilver.net/license.hdf
 *
 */

#include "config.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "neo_misc.h"
#include "neo_err.h"
#include "neo_files.h"
#include "ulocks.h"

NEOERR *fCreate(int *plock, const char *file) 
{
  NEOERR *err;
  int lock;
  char *p;

  *plock = -1;

  /* note the default mode of 666 is possibly a security hole in that
   * someone else can grab your lock and DoS you.  For internal use, who
   * cares?
   */
  if((lock = open(file, O_WRONLY|O_NDELAY|O_APPEND|O_CREAT|O_EXCL, 0666)) < 0) 
  {
    if (errno == ENOENT)
    {
      p = strrchr (file, '/');
      if (p != NULL)
      {
	*p = '\0';
	err = ne_mkdirs(file, 0777);
	*p = '/';
	if (err != STATUS_OK) return nerr_pass(err);
	lock = open(file, O_WRONLY|O_NDELAY|O_APPEND|O_CREAT, 0666);
      }
    }
    if (errno == EEXIST)
      return nerr_pass(fFind(plock, file));

    if (lock < 0)
      return nerr_raise_errno (NERR_IO, "Unable to open lock file %s", file);
  }

  *plock = lock;

  return STATUS_OK;
}

void fDestroy(int lock) 
{

  if(lock < 0)
    return;

  close(lock);

  return;
}

NEOERR *fFind(int *plock, const char *file) 
{
  int lock;

  *plock = -1;

  if((lock = open(file, O_WRONLY|O_NDELAY|O_APPEND, 0666)) < 0) {
    if (errno == ENOENT)
      return nerr_raise (NERR_NOT_FOUND, "Unable to find lock file %s", file);
    return nerr_raise_errno (NERR_IO, "Unable to open lock file %s", file);
  }

  *plock = lock;

  return STATUS_OK;
}

NEOERR *fLock(int lock) 
{

  if(lockf(lock, F_LOCK, 0) < 0)
    return nerr_raise_errno (NERR_LOCK, "File lock failed");

  return STATUS_OK;
}

void fUnlock(int lock) 
{

  if(lock < 0)
    return;

  lockf(lock, F_ULOCK, 0);

  return;
}

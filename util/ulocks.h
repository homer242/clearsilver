/*
 *
 * Thread-safe Skiplist Using Integer Identifiers
 * Copyright 1998-2000 Scott Shambarger (scott@shambarger.net)
 *
 * This software is open source. Permission to use, copy, modify, and
 * distribute this software for any purpose and without fee is hereby granted,
 * provided that the above copyright notice appear in all copies.  No
 * warranty of any kind is expressed or implied.  Use at your own risk.
 *
 * 1/14/2001 blong
 *   Made it use neo errs... probably need to check locking functions
 *   for error returns...
 *
 */

#ifndef __ULOCKS_H_
#define __ULOCKS_H_

#include "neo_err.h"

NEOERR *fCreate(int *plock, const char *file);
/*
 * Function:    fCreate - create a file lock.
 * Description: Creates a file lock on named file <file>.  The lock is
 *              returned in <plock>.
 * Input:       plock - place for lock.
 *              file - path of file to use as lock.
 * Output:      plock - set to lock identifier.
 * Return:      STATUS_OK on success
 *              NERR_IO on failure
 * MT-Level:    Safe.
 */

NEOERR *fFind(int *plock, const char *file);
/*
 * Function:    fFind - find a file lock.
 * Description: Find a file identified by the path <file>, and returns a 
 *              lock identifier for it in <plock>.  If the file doesn't
 *              exist, returns true.
 * Input:       plock - place for lock.
 *              file - path of file to use as lock.
 * Output:      plock - set to lock identifier.
 * Return:      STATUS_OK if found
 *              NERR_IO on failure
 * MT-Level:    Safe.
 */

void fDestroy(int lock);
/*
 * Function:    fDestroy - destroy a lock.
 * Description: Destroys the lock <lock> that was created by fCreate()
 *              or fFind().
 * Input:       lock - Lock to destroy.
 * Output:      None.
 * Return:      None.
 * MT-Level:    Safe for unique <lock>.
 */

NEOERR *fLock(int lock);
/*
 * Function:    fLock - acquire file lock.
 * Description: Acquires the lock identified by <lock>.  This call
 *              blocks until the lock is acquired.
 * Input:       lock - Lock to acquire.
 * Output:      None.
 * Return:      STATUS_OK on success
 *              NERR_LOCK on failure
 * MT-Level:    Safe.
 */

void fUnlock(int lock);
/*
 * Function:    fUnlock - release file lock.
 * Description: Releases the lock identified by <lock>.
 * Input:       lock - Lock to release.
 * Output:      None.
 * Return:      None.
 * MT-Level:    Safe.
 */

#endif                                                       /* __ULOCKS_H_ */

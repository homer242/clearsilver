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

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "util/neo_misc.h"
#include "util/neo_hdf.h"
#include "cs.h"

static NEOERR *output (void *ctx, char *s)
{
  printf ("%s", s);
  return STATUS_OK;
}

NEOERR *test_strfunc(const char *str, char **ret)
{
  char *s = strdup(str);
  int x = 0;

  if (s == NULL)
    return nerr_raise(NERR_NOMEM, "Unable to duplicate string in test_strfunc");

  while (s[x]) {
    s[x] = tolower(s[x]);
    x++;
  }
  *ret = s;
  return STATUS_OK;
}


int main (int argc, char *argv[])
{
  NEOERR *err;
  CSPARSE *parse;
  HDF *hdf;
  int verbose = 0;
  char *hdf_file, *cs_file;

  if (argc < 3)
  {
    ne_warn ("Usage: cstest [-v] <file.hdf> <file.cs>");
    return -1;
  }

  if (!strcmp(argv[1], "-v"))
  {
    verbose = 1;
    if (argc < 4)
    {
      ne_warn ("Usage: cstest [-v] <file.hdf> <file.cs>");
      return -1;
    }
    hdf_file = argv[2];
    cs_file = argv[3];
  }
  else
  {
    hdf_file = argv[1];
    cs_file = argv[2];
  }

  err = hdf_init(&hdf);
  if (err != STATUS_OK)
  {
    nerr_log_error(err);
    return -1;
  }
  err = hdf_read_file(hdf, hdf_file);
  if (err != STATUS_OK)
  {
    nerr_log_error(err);
    return -1;
  }

  printf ("Parsing %s\n", cs_file);
  err = cs_init (&parse, hdf);
  if (err != STATUS_OK)
  {
    nerr_log_error(err);
    return -1;
  }

  /* register a test strfunc */
  err = cs_register_strfunc(parse, "test_strfunc", test_strfunc);
  if (err != STATUS_OK) 
  {
    nerr_log_error(err);
    return -1;
  }

  err = cs_parse_file (parse, cs_file);
  if (err != STATUS_OK)
  {
    err = nerr_pass(err);
    nerr_log_error(err);
    return -1;
  }

  err = cs_render(parse, NULL, output);
  if (err != STATUS_OK)
  {
    err = nerr_pass(err);
    nerr_log_error(err);
    return -1;
  }

  if (verbose)
  {
    printf ("\n-----------------------\nCS DUMP\n");
    err = cs_dump(parse, NULL, output);
  }

  cs_destroy (&parse);

  if (verbose)
  {
    printf ("\n-----------------------\nHDF DUMP\n");
    hdf_dump (hdf, NULL);
  }
  hdf_destroy(&hdf);


  return 0;
}

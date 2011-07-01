lib_LTLIBRARIES = libneo_utl.la
NEO_UTL_LIBRARY_VERSION=1:0:0

EXTRA_UTL_SRC=@EXTRA_UTL_SRC@
libneo_utl_la_SOURCES = neo_err.c neo_files.c neo_misc.c neo_rand.c \
	ulist.c neo_hdf.c neo_str.c neo_date.c wildmat.c neo_hash.c

ifeq (@cs_cv_have_lockf@,yes)
EXTRA_UTL_SRC += ulocks.c rcfs.c
fi

ifeq (@cs_cv_have_pthread@,yes)
EXTRA_UTL_SRC += skiplist.c dict.c
fi

ifeq (@cs_cv_have_snprintf@,yes)
EXTRA_UTL_SRC += snprintf.c
fi

ifneq (@cs_cv_have_regex@,yes)
EXTRA_UTL_SRC += regex/regex.c
fi

ifeq (@cs_cv_missing@,yes)
EXTRA_UTL_SRC += missing.c
fi

ifneq (@MINGW32@,yes)
EXTRA_UTL_SRC += filter.c neo_net.c neo_server.c
fi

libneo_utl_la_LDFLAGS = -version-info $(NEO_UTL_LIBRARY_VERSION)

library_includedir=$(includedir)/ClearSilver/util
library_include_HEADERS = neo_err.h neo_files.h neo_misc.h neo_rand.h \
	ulist.h neo_hdf.h neo_str.h neo_date.h wildmat.h neo_hash.h \
        $(EXTRA_UTL_SRC):%.c=%.h)

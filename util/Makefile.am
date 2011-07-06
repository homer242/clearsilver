lib_LTLIBRARIES = libneo_utl.la
NEO_UTL_LIBRARY_VERSION=1:0:0

library_includedir=$(includedir)/ClearSilver/util
library_include_HEADERS = neo_err.h neo_files.h neo_misc.h neo_rand.h \
	ulist.h neo_hdf.h neo_str.h neo_date.h wildmat.h neo_hash.h

libneo_utl_la_SOURCES = neo_err.c neo_files.c neo_misc.c neo_rand.c \
	ulist.c neo_hdf.c neo_str.c neo_date.c wildmat.c neo_hash.c
libneo_utl_la_LDFLAGS = -version-info $(NEO_UTL_LIBRARY_VERSION)

if USE_WDB
libneo_utl_la_SOURCES += wdb.c
library_include_HEADERS += wdb.h
endif

if USE_LOCKF
libneo_utl_la_SOURCES += ulocks.c rcfs.c
library_include_HEADERS += ulocks.h rcfs.h
endif

if USE_PTHREAD
libneo_utl_la_SOURCES += plocks.c skiplist.c dict.c
library_include_HEADERS += plocks.h skiplist.h dict.h
endif

if USE_BUILTIN_SNPRINTF
libneo_utl_la_SOURCES += snprintf.c
library_include_HEADERS += snprintf.h
endif

if USE_BUILTIN_REGEXEC
libneo_utl_la_SOURCES += regex/regex.c
library_include_HEADERS += regex/regex.h
endif

if USE_BUILTIN_MISSING_FUNC
libneo_utl_la_SOURCES += missing.c
library_include_HEADERS += missing.h
endif

if !ON_MINGW32
libneo_utl_la_SOURCES += filter.c neo_net.c neo_server.c
library_include_HEADERS += filter.h neo_net.h neo_server.h
endif


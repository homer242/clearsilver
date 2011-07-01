lib_LTLIBRARIES = libneo_cs.la
NEO_CS_LIBRARY_VERSION=1:0:0

libneo_cs_la_SOURCES = csparse.c
libneo_cs_la_LDFLAGS = -version-info $(NEO_CGI_LIBRARY_VERSION)

library_includedir=$(includedir)/ClearSilver/cs
library_include_HEADERS = cgi.h \
			cgiwrap.h \
			date.h \
			html.h

# test
TESTS = cstest

check_PROGRAMS = $(TESTS)

cstest_SOURCES = cstest.c
cstest_LDADD = libneo_cs.la
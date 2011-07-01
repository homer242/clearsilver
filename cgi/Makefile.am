lib_LTLIBRARIES = libneo_cgi.la
NEO_CGI_LIBRARY_VERSION=1:0:0

libneo_cgi_la_SOURCES = cgiwrap.c cgi.c html.c date.c rfc2388.c
libneo_cgi_la_LDFLAGS = -version-info $(NEO_CGI_LIBRARY_VERSION)

library_includedir=$(includedir)/ClearSilver/cgi
library_include_HEADERS = cgi.h \
			cgiwrap.h \
			date.h \
			html.h

# test
TESTS = cgi_cstest

check_PROGRAMS = $(TESTS)

cgi_cstest_SOURCES = cgi_cstest.c
cgi_cstest_LDADD = libneo_cgi.la
pkglib_PROGRAMS = clearsilver.dll
clearsilver_dll_SOURCES = CS.cs
clearsilver.dll : $(clearsilver_dll_SOURCES)
	$(CSC) $(clearsilver_dll_LDFLAGS) $^ -o $@

# test
TESTS = cstest.exe csperftest.exe

check_PROGRAMS = $(TESTS)

cstest_exe_SOURCES = cgi_cstest.cs
cstest_exe_LDADD = -lclearsilver.dll

csperftest_exe_SOURCES = csperftest.cs
csperftest_exe_LDADD = -lclearsilver.dll

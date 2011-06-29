#!/bin/sh

aclocal \
&& automake --add-missing \
&& autoheader \
&& autoconf

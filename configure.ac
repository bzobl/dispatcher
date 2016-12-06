#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.69)
AC_INIT([dispatcher], [0.1], [bzobl@gmx.net])
AC_LANG(C++)

AM_INIT_AUTOMAKE([subdir-objects])

AC_PROG_CC
AC_PROG_CXX

PKG_CHECK_MODULES([GLIB], [glib-2.0])
AC_SUBST(GLIB_LIBS, `$PKG_CONFIG --libs glib-2.0`)
AC_SUBST(GLIB_CFLAGS, `$PKG_CONFIG --cflags glib-2.0`)

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

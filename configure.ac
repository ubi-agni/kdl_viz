AC_INIT([cbf], [0.1], [nst@techfak.uni-bielefeld.de])
AM_INIT_AUTOMAKE([-Wall foreign])

AC_CONFIG_MACRO_DIR([m4])

AC_PROG_CC
AC_PROG_CXX
AC_PROG_LIBTOOL



AC_ARG_WITH(
	[kdl-dir], 
	AS_HELP_STRING(
		[--with-kdl-dir=DIR],
		[Specify the PREFIX where the kdl libs can be found]
	),
	[with_kdl_dir=$withval],
	[with_kdl_dir=/usr]
)



# Check for Boost stuff
AX_BOOST_BASE(1.33.1)

# Make sure pkg-config is at least at version 0.9
PKG_PROG_PKG_CONFIG

# Check for KDL support
PKG_CONFIG_PATH=$with_kdl_dir/lib/pkgconfig:$PKG_CONFIG_PATH

PKG_CHECK_MODULES([KDL], [orocos-kdl >= 0.99])

echo KDL_CXXFLAGS:  $KDL_CXXFLAGS
echo KDL_CFLAGS:    $KDL_CFLAGS
echo KDL_LIBS:      $KDL_LIBS
echo KDL_CPPFLAGS:  $KDL_CPPFLAGS

AM_CONDITIONAL([HAVE_KDL], [test $DO_HAVE_KDL = 1])

LD_LIBRARY_PATH=$with_kdl_dir/lib:$LD_LIBRARY_PATH

# Check for Qt moc utility 
AC_PATH_PROG(ac_moc, moc, no)
if test "x$ac_moc" = "xno"; then
    AC_MSG_ERROR([moc $ac_errmsg])
fi

echo Found moc: $ac_moc

PKG_PROG_PKG_CONFIG

PKG_CHECK_MODULES(QTCORE, QtCore)
PKG_CHECK_MODULES(QTGUI, QtGui)
PKG_CHECK_MODULES(QTGL, QtOpenGl)

LIBS="$QTCORE_LIBS $QTGUI_LIBS $QTGL_LIBS $LIBS"
CFLAGS="$QTCORE_CFLAGS $QTGUI_CFLAGS $QTGL_CFLAGS $CFLAGS"
CXXFLAGS="$QTCORE_CFLAGS $QTGUI_CFLAGS $QTGL_CXXFLAGS $CXXFLAGS"
CPPFLAGS="$QTCORE_CPPFLAGS $QTGUI_CPPFLAGS $QTGL_CPPFLAGS $CPPFLAGS"


# And finally output the results
AC_CONFIG_FILES([
	Makefile
	src/Makefile
	test/Makefile
])

AC_OUTPUT


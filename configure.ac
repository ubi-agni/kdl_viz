AC_INIT([kdlchainview], [0.3], [fschmidt@techfak.uni-bielefeld.de])
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

AC_ARG_WITH(
	[qt-dir], 
	AS_HELP_STRING(
		[--with-qt-dir=DIR],
		[Specify the PREFIX where the qt libs can be found]
	),
	[with_qt_dir=$withval],
	[with_qt_dir=/usr]
)

# Check for Boost stuff
AX_BOOST_BASE(1.33.1)

# Make sure pkg-config is at least at version 0.9
PKG_PROG_PKG_CONFIG

# We need at the very least OpenGL
AX_CHECK_GL

# Check for KDL support
PKG_CONFIG_PATH=$with_kdl_dir/lib/pkgconfig:$PKG_CONFIG_PATH

PKG_CHECK_MODULES([KDL], [orocos-kdl >= 0.99])

#echo KDL_CXXFLAGS:  $KDL_CXXFLAGS
#echo KDL_CFLAGS:    $KDL_CFLAGS
#echo KDL_LIBS:      $KDL_LIBS
#echo KDL_CPPFLAGS:  $KDL_CPPFLAGS

#CXXFLAGS="$KDL_CFLAGS $CXXFLAGS"
#CFLAGS="$KDL_CFLAGS $CFLAGS"
#CPPFLAGS="$KDL_CPPFLAGS $CPPFLAGS"
#LIBS="$KDL_LIBS $LIBS"

PKG_CONFIG_PATH=$with_qt_dir/lib/pkgconfig:$PKG_CONFIG_PATH

PKG_CHECK_MODULES(QT, QtCore QtGui QtOpenGL, [DO_HAVE_QT=1;], AC_MSG_NOTICE([Qt4 not found... Not building Qt widgets]); DO_HAVE_QT=0;)

AM_CONDITIONAL([HAVE_QT], [test $DO_HAVE_QT=1])

#LIBS="$QT_LIBS $LIBS"
#CFLAGS="$QT_CFLAGS $CFLAGS"
#CXXFLAGS="$QT_CFLAGS $CXXFLAGS"
#CPPFLAGS="$QT_CPPFLAGS $CPPFLAGS"

if test $DO_HAVE_QT = 1; then
	AX_CHECK_GLU
	ac_moc=`$PKG_CONFIG --variable moc_location QtCore`
	AC_SUBST(ac_moc)

	echo Found moc: $ac_moc

#	AX_CREATE_PKGCONFIG_INFO(
#		libqkdlchainwidget.pc,
#		orocos-kdl >= 99 QtCore QtGui QtOpenGL,
#		[-lqkdlchainwidget],
#		[A Qt widget for visualizing a KDL::Chain],
#		[],
#		[]
#	)
fi

#AX_CREATE_PKGCONFIG_INFO(
#	libkdlchainview.pc,
#	orocos-kdl >= 99 QtCore QtGui QtOpenGL,
#	[-L${libdir} -lkdlchainview],
#	[A class to visualize a KDL::Chain],
#	[-I${includedir}],
#	[-L${libdir} -lkdlchainview]
#)


# And finally output the results
AC_CONFIG_FILES([
	Makefile
	src/Makefile
	test/Makefile
])

AC_OUTPUT


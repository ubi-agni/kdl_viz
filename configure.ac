AC_INIT([kdlchainview], [0.3], [fschmidt@techfak.uni-bielefeld.de])
AM_INIT_AUTOMAKE([foreign -Wall -Wno-portability])

AC_CONFIG_MACRO_DIR([m4])

AM_PROG_AR
AC_PROG_CC
AC_PROG_CXX
LT_INIT([pic-only disable-static])

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

# We need at the very least OpenGL
AX_CHECK_GL
AX_CHECK_GLU

# Check for KDL support
PKG_CONFIG_PATH=$with_kdl_dir/lib/pkgconfig:$PKG_CONFIG_PATH
PKG_CHECK_MODULES([KDL], [orocos-kdl >= 0.99])

echo KDL_CXXFLAGS:  $KDL_CXXFLAGS
echo KDL_LIBS:      $KDL_LIBS

# Check for Qt4 or Qt5
QT_CHECK(QtCore QtGui QtOpenGL, Qt5Core Qt5Widgets Qt5OpenGL)

# And finally output the results
AC_CONFIG_FILES([
	Makefile
	src/Makefile
	test/Makefile
])

AC_OUTPUT


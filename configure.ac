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

PKG_CHECK_MODULES([KDL], [orocos-kdl >= 0.99], [DO_HAVE_KDL=1], DO_HAVE_KDL=0; AC_MSG_WARN([KDL not found. Will build without KDL support]))

echo KDL_CXXFLAGS:  $KDL_CXXFLAGS
echo KDL_CFLAGS:    $KDL_CFLAGS
echo KDL_LIBS:      $KDL_LIBS
echo KDL_CPPFLAGS:  $KDL_CPPFLAGS

AM_CONDITIONAL([HAVE_KDL], [test $DO_HAVE_KDL = 1])

LD_LIBRARY_PATH=$with_kdl_dir/lib:$LD_LIBRARY_PATH


# And finally output the results
AC_CONFIG_FILES([
	Makefile
	src/Makefile
	test/Makefile
])

AC_OUTPUT


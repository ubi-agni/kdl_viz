# ===========================================================================
#        http://www.gnu.org/software/autoconf-archive/ax_have_qt.html
# ===========================================================================
#
# SYNOPSIS
#
#   QTCHECK(QtCore >= x.y QtXml >= x.y)
#
#   Additionally, the following variables are exported:
#
#     QT_CPPFLAGS
#     QT_LIBS
#     QT_MOC
#     QT_VERSION
#     QT_DIR
#
#   No common variables such as $LIBS or $CFLAGS are polluted.
#
#   Options:
#
#   --with-qt-dir=DIR: path to qmake

AC_DEFUN([QT_CHECK],
[
  AC_REQUIRE([AC_PROG_CXX])
  AC_MSG_CHECKING(whether Qt should be used)

  AC_ARG_WITH([qt-dir],
              AS_HELP_STRING([--with-qt-dir=DIR],
                             [specify Qt base dir]))

  if test x"$with_qt_dir" = x"no" ; then
    # user disabled Qt. 
    HAVE_QT=0
    AC_MSG_RESULT(no)
  else
    AC_MSG_RESULT(yes)
    # "yes" is a bogus option
    if test x"$with_qt_dir" = xyes; then
      with_qt_dir=
    fi
    ac_save_pkgcfg_path=$PKG_CONFIG_PATH

    # try "old" Qt
    PKG_CHECK_MODULES(QT, $1, HAVE_QT=1, HAVE_QT=0)
    if test -n "$QT_LIBS"; then
      AC_SUBST(QT_VERSION,`pkg-config --modversion QtCore`)
    else
      # try Qt5
      PKG_CHECK_MODULES(QT, $2, HAVE_QT=1, HAVE_QT=0)
      if test -n "$QT_LIBS"; then
        AC_SUBST(QT_VERSION,`pkg-config --modversion Qt5Core`)
		  AC_SUBST(QT5_CXXFLAGS,-fPIC)
      fi
    fi
    AC_SUBST(ac_moc,`which moc`)
    PKG_CONFIG_PATH=$ac_save_pkgcfg_path
  fi
  AM_CONDITIONAL(HAVE_QT, test "$HAVE_QT" = "1")
])

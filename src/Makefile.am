

lib_LTLIBRARIES = \
  libkdlchainview.la \
  libkdltreeview.la

# CHAIN STUFF

libkdlchainview_la_SOURCES = \
  kdlchainview.cc \
  kdlchainview.h

include_HEADERS = \
  kdlchainview.h

libkdlchainview_la_LDFLAGS = $(GL_LIBS) $(KDL_LIBS) $(AM_LIBS)

libkdlchainview_la_CXXFLAGS = $(GL_CFLAGS) $(KDL_CFLAGS) $(AM_CXXFLAGS)

libkdlchainview_la_CPPFLAGS = $(GL_CPPFLAGS) $(KDL_CPPFLAGS) $(AM_CPPFLAGS)

# TREE STUFF

libkdltreeview_la_SOURCES = \
  kdltreeview.cc \
  kdltreeview.h

include_HEADERS += \
  kdltreeview.h

libkdltreeview_la_LDFLAGS = $(GL_LIBS) $(KDL_LIBS) $(AM_LIBS)

libkdltreeview_la_CXXFLAGS = $(GL_CFLAGS) $(KDL_CFLAGS) $(AM_CXXFLAGS)

libkdltreeview_la_CPPFLAGS = $(GL_CPPFLAGS) $(KDL_CPPFLAGS) $(AM_CPPFLAGS)


if HAVE_QT

# CHAIN STUFF

lib_LTLIBRARIES += \
  libqkdlchainview.la

libqkdlchainview_la_SOURCES = \
  qkdlchainwidget.cc \
  qkdlchainwidget.h \
  qkdlchainview.cc \
  qkdlchainview.h

libqkdlchainview_la_CXXFLAGS = $(QT_CFLAGS) $(KDL_CFLAGS) $(AM_CXXFLAGS) $(GLU_CFLAGS)

libqkdlchainview_la_LDFLAGS = $(QT_LDFLAGS) $(KDL_LDFLAGS) $(AM_LDFLAGS) $(GLU_LIBS)

libqkdlchainview_la_LIBADD = libkdlchainview.la

include_HEADERS += \
  qkdlchainwidget.h \
  qkdlchainview.h

nodist_libqkdlchainview_la_SOURCES = \
  qkdlchainwidget.moc.cc \
  qkdlchainview.moc.cc


# TREE STUFF

lib_LTLIBRARIES += \
  libqkdltreeview.la

libqkdltreeview_la_SOURCES = \
  qkdltreewidget.cc \
  qkdltreewidget.h \
  qkdltreeview.cc \
  qkdltreeview.h

libqkdltreeview_la_CXXFLAGS = $(QT_CFLAGS) $(KDL_CFLAGS) $(AM_CXXFLAGS) $(GLU_CFLAGS)

libqkdltreeview_la_LDFLAGS = $(QT_LDFLAGS) $(KDL_LDFLAGS) $(AM_LDFLAGS) $(GLU_LIBS)

libqkdltreeview_la_LIBADD = libkdltreeview.la

include_HEADERS += \
  qkdltreewidget.h \
  qkdltreeview.h

nodist_libqkdltreeview_la_SOURCES = \
  qkdltreewidget.moc.cc \
  qkdltreeview.moc.cc

%.moc.cc: %.h
	@ac_moc@ -o $@ $<


clean-local:
	rm -f *.moc.cc

endif

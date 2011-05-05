lib_LTLIBRARIES = libkdlview.la

libkdlview_la_SOURCES = \
  kdlchainview.cc \
  kdlchainview.h \
  kdltreeview.cc \
  kdltreeview.h

include_HEADERS = \
  kdlchainview.h \
  kdltreeview.h

libkdlview_la_LDFLAGS = $(GL_LIBS) $(KDL_LIBS) $(AM_LIBS)
libkdlview_la_CXXFLAGS = $(GL_CFLAGS) $(KDL_CFLAGS) $(AM_CXXFLAGS)
libkdlview_la_CPPFLAGS = $(GL_CPPFLAGS) $(KDL_CPPFLAGS) $(AM_CPPFLAGS)

if HAVE_QT

lib_LTLIBRARIES += \
  libqkdlview.la

libqkdlview_la_SOURCES = \
  qkdlchainwidget.cc \
  qkdlchainwidget.h \
  qkdlchainview.cc \
  qkdlchainview.h \
  qkdltreewidget.cc \
  qkdltreewidget.h \
  qkdltreeview.cc \
  qkdltreeview.h

libqkdlview_la_CXXFLAGS = $(QT_CFLAGS) $(KDL_CFLAGS) $(AM_CXXFLAGS) $(GLU_CFLAGS)
libqkdlview_la_LDFLAGS = $(QT_LIBS) $(KDL_LDFLAGS) $(AM_LDFLAGS) $(GLU_LIBS)
libqkdlview_la_LIBADD = libkdlview.la

include_HEADERS += \
  qkdlchainwidget.h \
  qkdlchainview.h \
  qkdltreewidget.h \
  qkdltreeview.h

nodist_libqkdlview_la_SOURCES = \
  qkdlchainwidget.moc.cc \
  qkdlchainview.moc.cc \
  qkdltreewidget.moc.cc \
  qkdltreeview.moc.cc

%.moc.cc: %.h
	@ac_moc@ -o $@ $<

clean-local:
	rm -f *.moc.cc

endif

lib_LTLIBRARIES = \
  libkdlchainview.la

libkdlchainview_la_SOURCES = \
  kdlchainview.cc \
  kdlchainview.h

include_HEADERS = \
  kdlchainview.h

libkdlchainview_la_LDFLAGS = $(GL_LIBS) $(KDL_LIBS) $(AM_LIBS)

libkdlchainview_la_CXXFLAGS = $(GL_CFLAGS) $(KDL_CFLAGS) $(AM_CXXFLAGS)

libkdlchainview_la_CPPFLAGS = $(GL_CPPFLAGS) $(KDL_CPPFLAGS) $(AM_CPPFLAGS)

if HAVE_QT
lib_LTLIBRARIES += \
  libqkdlchainview.la

libqkdlchainview_la_SOURCES = \
  qkdlchainwidget.cc \
  qkdlchainwidget.h \
  qkdlchainview.cc \
  qkdlchainview.h

libqkdlchainview_la_CXXFLAGS = $(QT_CFLAGS) $(KDL_CFLAGS) $(AM_CXXFLAGS)

libqkdlchainview_la_LDFLAGS = $(QT_LDFLAGS) $(KDL_LDFLAGS) $(AM_LDFLAGS)

libqkdlchainview_la_LIBADD = libkdlchainview.la

include_HEADERS += \
  qkdlchainwidget.h \
  qkdlchainview.h

nodist_libqkdlchainview_la_SOURCES = \
  qkdlchainwidget.moc.cc \
  qkdlchainview.moc.cc


%.moc.cc: %.h
	@ac_moc@ -o $@ $<

clean-local:
	rm -f *.moc.cc
endif


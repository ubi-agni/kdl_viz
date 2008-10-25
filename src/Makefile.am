lib_LTLIBRARIES = \
  libkdlchainview.la

libkdlchainview_la_SOURCES = \
  kdlchainview.cc

include_HEADERS = \
  kdlchainview.h

libkdlchainview_la_LDFLAGS = $(GL_LIBS) $(AM_LIBS)

libkdlchainview_la_CXXFLAGS = $(GL_CFLAGS) $(AM_CXXFLAGS)

if HAVE_QT
lib_LTLIBRARIES += \
  libqkdlchainwidget.la

libqkdlchainwidget_la_SOURCES = \
  qkdlchainwidget.cc

libqkdlchainwidget_la_CXXFLAGS = $(QT_CFLAGS) $(AM_CXXFLAGS)

libqkdlchainwidget_la_LDFLAGS = $(QT_LDFLAGS) $(AM_LDFLAGS)

libqkdlchainwidget_la_LIBADD = libkdlchainview.la

include_HEADERS += \
  qkdlchainwidget.h

nodist_libqkdlchainwidget_la_SOURCES = \
  qkdlchainwidget.moc.cc




%.moc.cc: %.h
	@ac_moc@ -o $@ $<

clean-local:
	rm -f *.moc.cc
endif


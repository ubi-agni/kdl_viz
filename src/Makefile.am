lib_LTLIBRARIES = \
  libkdlchainview.la

libkdlchainview_la_SOURCES = \
  kdlchainview.cc

include_HEADERS = \
  kdlchainview.h

libkdlchainview_la_LDFLAGS = $(GL_LIBS) $(AM_LIBS)

libkdlchainview_la_CFLAGS = $(GL_CFLAGS) $(AM_CFLAGS)

if HAVE_QT
lib_LTLIBRARIES += \
  libqkdlchainwidget.la

libqkdlchainwidget_la_SOURCES = \
  qkdlchainwidget.cc

include_HEADERS += \
  qkdlchainwidget.h

nodist_libqkdlchainwidget_la_SOURCES = \
  qkdlchainwidget.moc.cc


%.moc.cc: %.h
	@ac_moc@ -o $@ $<

clean-local:
	rm -f *.moc.cc
endif


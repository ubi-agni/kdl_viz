bin_PROGRAMS = 

if HAVE_QT
bin_PROGRAMS += test_qkdlchainwidget

test_qkdlchainwidget_SOURCES = test_qkdlchainwidget.cc test_timer.cc
test_qkdlchainwidget_CXXFLAGS = -I ../src $(QT_CFLAGS) $(AM_CPPFLAGS) $(KDL_CFLAGS)
test_qkdlchainwidget_LDFLAGS = $(AM_LIBS) $(QT_LIBS) $(KDL_LIBS)
test_qkdlchainwidget_LDADD = ..//src/libqkdlchainview.la 

nodist_test_qkdlchainwidget_SOURCES = test_timer.moc.cc

include_HEADERS = \
  test_timer.h

%.moc.cc: %.h
	@ac_moc@ -o $@ $<

clean-local:
	rm -f *.moc.cc
endif


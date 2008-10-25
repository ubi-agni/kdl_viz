bin_PROGRAMS = 

if HAVE_QT
bin_PROGRAMS += test_qkdlchainwidget

test_qkdlchainwidget_SOURCES = test_qkdlchainwidget.cc test_timer.cc
test_qkdlchainwidget_CPPFLAGS = -I ../src $(AM_CPPFLAGS)
test_qkdlchainwidget_LDADD = ..//src/libqkdlchainwidget.la $(AM_LIBS)

nodist_test_qkdlchainwidget_SOURCES = test_timer.moc.cc

include_HEADERS = \
  test_timer.h

%.moc.cc: %.h
	@ac_moc@ -o $@ $<

clean-local:
	rm -f *.moc.cc
endif


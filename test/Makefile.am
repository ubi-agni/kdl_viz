bin_PROGRAMS = 

if HAVE_QT

bin_PROGRAMS += test_qkdlchainwidget

AM_CXXFLAGS = -I$(top_srcdir)/src $(QT_CFLAGS) $(QT5_CXXFLAGS) $(AM_CPPFLAGS) $(KDL_CFLAGS)
AM_LDFLAGS  = $(AM_LIBS) $(QT_LIBS) $(KDL_LIBS)

nodist_test_qkdlchainwidget_SOURCES = test_chain_timer.moc.cc
test_qkdlchainwidget_SOURCES = test_qkdlchainwidget.cc test_chain_timer.cc
test_qkdlchainwidget_LDADD = ../src/libqkdlview.la 


bin_PROGRAMS += test_qkdltreewidget

nodist_test_qkdltreewidget_SOURCES = test_tree_timer.moc.cc
test_qkdltreewidget_SOURCES = test_qkdltreewidget.cc test_tree_timer.cc
test_qkdltreewidget_LDADD = ../src/libqkdlview.la 


%.moc.cc: %.h
	@ac_moc@ -o $@ $<

clean-local:
	rm -f *.moc.cc
endif


bin_PROGRAMS = 

if HAVE_QT
bin_PROGRAMS += test_qkdlchainwidget

test_qkdlchainwidget_SOURCES = test_qkdlchainwidget.cc test_chain_timer.cc
test_qkdlchainwidget_CXXFLAGS = -I ../src $(QT_CFLAGS) $(AM_CPPFLAGS) $(KDL_CFLAGS)
test_qkdlchainwidget_LDFLAGS = $(AM_LIBS) $(QT_LIBS) $(KDL_LIBS)
test_qkdlchainwidget_LDADD = ..//src/libqkdlchainview.la 

nodist_test_qkdlchainwidget_SOURCES = test_chain_timer.moc.cc

bin_PROGRAMS += test_qkdltreewidget

test_qkdltreewidget_SOURCES = test_qkdltreewidget.cc test_tree_timer.cc
test_qkdltreewidget_CXXFLAGS = -I ../src $(QT_CFLAGS) $(AM_CPPFLAGS) $(KDL_CFLAGS)
test_qkdltreewidget_LDFLAGS = $(AM_LIBS) $(QT_LIBS) $(KDL_LIBS)
test_qkdltreewidget_LDADD = ..//src/libqkdltreeview.la 

nodist_test_qkdltreewidget_SOURCES = test_tree_timer.moc.cc



include_HEADERS = \
  test_chain_timer.h \
  test_tree_timer.h

%.moc.cc: %.h
	@ac_moc@ -o $@ $<

clean-local:
	rm -f *.moc.cc
endif


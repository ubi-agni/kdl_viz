bin_PROGRAMS = test_kdl_chain_viz

test_kdl_chain_viz_SOURCES = test_kdl_chain_viz.cc test_timer.cc
test_kdl_chain_viz_CPPFLAGS = -I ../src $(AM_CPPFLAGS)
test_kdl_chain_viz_LDADD = ..//src/libkdl_chain_viz.la $(AM_LIBS)

nodist_test_kdl_chain_viz_SOURCES = test_timer.moc.cc

%.moc.cc: %.h
	@ac_moc@ -o $@ $<

clean-local:
	rm -f *.moc.cc



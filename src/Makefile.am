lib_LTLIBRARIES = libkdl_chain_viz.la

libkdl_chain_viz_la_SOURCES = \
  kdl_chain_viz.cc

include_HEADERS = \
  kdl_chain_viz.h

nodist_libkdl_chain_viz_la_SOURCES = \
  kdl_chain_viz.moc.cc

%.moc.cc: %.h
	@ac_moc@ -o $@ $<

clean-local:
	rm -f *.moc.cc



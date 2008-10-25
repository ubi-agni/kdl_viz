bin_PROGRAMS = test_cbf 

test_cbf_SOURCES = test_cbf.cc
test_cbf_CPPFLAGS = -I ../src
test_cbf_LDADD = ..//src/libcbf.la $(AM_LIBS)

if HAVE_KDL
bin_PROGRAMS += test_kdl_transforms
test_kdl_transforms_SOURCES = test_kdl_transforms.cc
test_kdl_transforms_CXXFLAGS = -I../src $(AM_CXXFLAGS) $(KDL_CFLAGS)
test_kdl_transforms_LDADD = ../src/libcbf.la $(KDL_LIBS) $(AM_LIBS)
test_kdl_transforms_CPPFLAGS = -I ../src
endif

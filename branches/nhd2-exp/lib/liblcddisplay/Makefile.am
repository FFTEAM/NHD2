INCLUDES = \
	-I$(top_srcdir)/lib \
	-I$(top_srcdir)/src \
	-I$(top_srcdir)/src/system \
	-I$(top_srcdir)/src/zapit/include/zapit \
	-I$(top_srcdir)/lib/connection \
	-I$(top_srcdir)/lib/libconfigfile \
	-I$(top_srcdir)/lib/libeventserver
	
noinst_LIBRARIES = liblcddisplay.a

liblcddisplay_a_SOURCES = lcddisplay.cpp fontrenderer.cpp

AM_CXXFLAGS = \
	@FREETYPE_CFLAGS@
INCLUDES = \
	-I$(top_srcdir)/lib \
	-I$(top_srcdir)/src/zapit/include/zapit \
	-I$(top_srcdir)/lib/connection \
	-I$(top_srcdir)/lib/libeventserver

noinst_LIBRARIES = libsectionsdclient.a

libsectionsdclient_a_SOURCES = sectionsdclient.cpp

bin_PROGRAMS = sectionsdcontrol

sectionsdcontrol_SOURCES = sectionsdcontrol.cpp
sectionsdcontrol_LDADD = \
	libsectionsdclient.a \
	$(top_builddir)/lib/connection/libtuxbox-connection.a

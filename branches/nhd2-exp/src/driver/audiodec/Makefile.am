INCLUDES = \
	-I$(top_srcdir)/src \
        -I$(top_srcdir)/lib \
	-I$(top_srcdir)/src/zapit/include/zapit \
	-I$(top_srcdir)/lib/libconfigfile \
        @FREETYPE_CFLAGS@

if BOXTYPE_COOLSTREAM
INCLUDES += -I$(top_srcdir)/src/zapit/include \
	-I$(top_srcdir)/lib/libcoolstream
else
INCLUDES += -I$(top_srcdir)/lib/libdvbapi
endif

if ENABLE_LIBEPLAYER3
INCLUDES += -I$(top_srcdir)/lib/libeplayer3/include
endif

noinst_LIBRARIES = libneutrino_driver_audiodec.a

libneutrino_driver_audiodec_a_SOURCES = \
	basedec.cpp \
	cdrdec.cpp \
	tag.c \
	mp3dec.cpp \
	wavdec.cpp \
	flacdec.cpp

 

AC_INIT(neutrinoHD2,1.0.1)
AM_INIT_AUTOMAKE(neutrinoHD2,1.0.1) 

TUXBOX_APPS
TUXBOX_APPS_DIRECTORY
TUXBOX_APPS_PKGCONFIG
TUXBOX_APPS_DVB
TUXBOX_APPS_DRIVER

TUXBOX_BOXTYPE

AC_PROG_CC
AC_PROG_CXX
AC_DISABLE_STATIC
AM_PROG_LIBTOOL

TUXBOX_APPS_LIB_CONFIG(CURL,curl-config)
TUXBOX_APPS_LIB_CONFIG(FREETYPE,freetype-config)
TUXBOX_APPS_LIB_PKGCONFIG_CHECK(ID3TAG,libid3tag)
if test x"$ID3TAG_EXISTS" != xyes; then
	TUXBOX_APPS_LIB_PKGCONFIG(ID3TAG,id3tag)
fi
TUXBOX_APPS_LIB_PKGCONFIG_CHECK(MAD,libmad)
if test x"$MAD_EXISTS" != xyes; then
	TUXBOX_APPS_LIB_PKGCONFIG(MAD,mad)
fi
TUXBOX_APPS_LIB_PKGCONFIG(PNG,libpng)
TUXBOX_APPS_LIB_PKGCONFIG(AVCODEC,libavcodec)
TUXBOX_APPS_LIB_PKGCONFIG(AVUTIL,libavutil)
TUXBOX_APPS_LIB_PKGCONFIG(AVFORMAT,libavformat)

# keybaord
AC_ARG_ENABLE(keyboard-no-rc,
         [  --enable-keyboard-no-rc             enable keyboard control, disable rc control],
         [AC_DEFINE(KEYBOARD_INSTEAD_OF_REMOTE_CONTROL,1,[enable keyboard control, disable rc control])])

# opengl framebuffer (x86)
AC_ARG_ENABLE(opengl,
	AS_HELP_STRING(--enable-opengl,include opengl framebuffer support for x86),
	,[enable_opengl=no])
AM_CONDITIONAL(USE_OPENGL,test "$enable_opengl" = "yes")

if test "$enable_opengl" = "yes"; then
AC_DEFINE(USE_OPENGL,1,[include opengl engine])
fi

# libeplayer3
AC_ARG_ENABLE(libeplayer3,
	AS_HELP_STRING(--enable-libeplayer3,include libeplayer3 as player engine support),
	,[enable_libeplayer3=no])
AM_CONDITIONAL(ENABLE_LIBEPLAYER3,test "$enable_libeplayer3" = "yes")

if test "$enable_libeplayer3" = "yes"; then
AC_DEFINE(ENABLE_LIBEPLAYER3,1,[include libeplayer3 as player engine support])
fi

# gstreamer
AC_ARG_ENABLE(gstreamer,
	AS_HELP_STRING(--enable-gstreamer,include gstreamer as player engine support),
	,[enable_gstreamer=no])
AM_CONDITIONAL(ENABLE_GSTREAMER,test "$enable_gstreamer" = "yes")

if test "$enable_gstreamer" = "yes"; then
AC_DEFINE(ENABLE_GSTREAMER,1,[include gstreamer as player engine support])
TUXBOX_APPS_LIB_PKGCONFIG(GST,gstreamer-0.10)
fi

# lcd
AC_ARG_ENABLE(lcd,
	AS_HELP_STRING(--enable-lcd,include lcd support),
	,[enable_lcd=no])
AM_CONDITIONAL(ENABLE_LCD,test "$enable_lcd" = "yes")

if test "$enable_lcd" = "yes"; then
AC_DEFINE(ENABLE_LCD,1,[include lcd support])
fi

# lcd updape
AM_CONDITIONAL(LCD_UPDATE,test "$enable_lcd_update" = "yes")

if test "$enable_lcd" = "yes"; then
AC_DEFINE(LCD_UPDATE,1,[include lcd update support])
fi

# lcdapi
AM_CONDITIONAL(ENABLE_LCDAPI,test "$enable_lcd" = "yes")

if test "$enable_lcd" = "yes"; then
AC_DEFINE(ENABLE_LCDAPI,1,[include lcd api support])
fi

# scart output
AC_ARG_ENABLE(scart,
	AS_HELP_STRING(--enable-scart,enable scart output),
	,[enable_scart=no])
AM_CONDITIONAL(ENABLE_SCART,test "$enable_scart" = "yes")

if test "$enable_scart" = "yes"; then
AC_DEFINE(ENABLE_SCART,1,[include scart output support])
fi

# ci-cam
AC_ARG_ENABLE(ci,
	AS_HELP_STRING(--enable-ci,enable ci cam),
	,[enable_ci=no])
AM_CONDITIONAL(ENABLE_CI,test "$enable_ci" = "yes")

if test "$enable_ci" = "yes"; then
AC_DEFINE(ENABLE_CI,1,[include ci cam support])
fi

# 4 digits
AC_ARG_ENABLE(4digits,
	AS_HELP_STRING(--enable-4digits,include 5 segment lcd support),
	,[enable_4digits=no])
AM_CONDITIONAL(ENABLE_4DIGITS,test "$enable_4digits" = "yes")

if test "$enable_4digits" = "yes"; then
AC_DEFINE(ENABLE_4DIGITS,1,[include 5 segment lcd support])
fi

# fribidi for testing
AC_ARG_ENABLE(fribidi,
	AS_HELP_STRING(--enable-fribidi,include fribidi support),
	,[enable_fribidi=no])
AM_CONDITIONAL(ENABLE_FRIBIDI,test "$enable_fribidi" = "yes")

if test "$enable_fribidi" = "yes"; then
AC_DEFINE(ENABLE_FRIBIDI,1,[include fribidi support])
fi

# function keys
AC_ARG_ENABLE(functionkeys,
	AS_HELP_STRING(--enable-functionkeys,include RC functions keys support),
	,[enable_functionkeys=no])
AM_CONDITIONAL(ENABLE_FUNCTIONKEYS,test "$enable_functionkeys" = "yes")

if test "$enable_functionkeys" = "yes"; then
AC_DEFINE(ENABLE_FUNCTIONKEYS,1,[include RC function keys support])
fi

AC_OUTPUT([
Makefile
lib/Makefile
lib/libconfigfile/Makefile
lib/connection/Makefile
lib/libeventserver/Makefile
lib/libmd5sum/Makefile
lib/libnet/Makefile
lib/libxmltree/Makefile
lib/sectionsdclient/Makefile
lib/timerdclient/Makefile
lib/libtuxtxt/Makefile
lib/libdvbsub/Makefile
lib/libupnpclient/Makefile
lib/liblcddisplay/Makefile
lib/libdvbapi/Makefile
lib/libeplayer3/Makefile
lib/jsoncpp/Makefile
src/nhttpd/Makefile
src/nhttpd/web/Makefile
src/nhttpd/web/images/Makefile
src/nhttpd/web/scripts/Makefile
src/nhttpd/web/languages/Makefile
src/nhttpd/tuxboxapi/Makefile
src/nhttpd/yhttpd_core/Makefile
src/nhttpd/yhttpd_mods/Makefile
src/Makefile
src/daemonc/Makefile
src/driver/pictureviewer/Makefile
src/driver/audiodec/Makefile
src/driver/Makefile
src/gui/Makefile
src/gui/bedit/Makefile
src/gui/widget/Makefile
src/system/Makefile
data/Makefile
data/fonts/Makefile
data/icons/Makefile
data/iso-codes/Makefile
data/inetradio/Makefile
data/locale/Makefile
data/config/Makefile
data/lcd/Makefile
data/lcd/icons/Makefile
data/lcd/clock/Makefile
data/themes/Makefile
data/webtv/Makefile
data/scripts/Makefile
src/sectionsd/Makefile
src/timerd/Makefile
src/zapit/Makefile
src/zapit/lib/Makefile
src/zapit/src/Makefile
])


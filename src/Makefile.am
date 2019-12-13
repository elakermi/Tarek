## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = gesthotexc

gesthotexc_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	hot1.c hot1.h \
	exc1.c exc1.h \
	profil.c profil.h

gesthotexc_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)


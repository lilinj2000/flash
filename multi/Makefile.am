AUTOMAKE_OPTIONS = foreign

SUBDIRS = mdflow

bin_PROGRAMS = flash_multi
flash_multi_SOURCES = \
	FlashMultiConfig.cc \
	MultiMDServer.cc \
	Main.cc 


flash_multi_CPPFLAGS = -I$(top_srcdir) \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(FOAL_CPPFLAGS) \
		$(AIR_CPPFLAGS)


flash_multi_LDADD = \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(FOAL_LIBADD) \
	$(AIR_LIBADD) \
	../util/.libs/libutil.a



flash_multi_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = FlashMultiConfig.hh \
		MultiMDServer.hh


EXTRA_DIST = multi_env.sh.example multi.cfg.example multi_log.cfg.example

flash_multidir = $(bindir)
flash_multi_DATA = $(EXTRA_DIST)

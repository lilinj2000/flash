AUTOMAKE_OPTIONS = foreign

SUBDIRS = mdflow

bin_PROGRAMS = flash
flash_SOURCES = \
	FlashConfig.cc \
	MDServer.cc \
	MultiMDServer.cc \
	FlashServer.cc \
	MData.cc \
	Main.cc 


flash_CPPFLAGS = -I$(top_srcdir) \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(ES_FEMA_CPPFLAGS)


flash_LDADD = \
	$(BOOST_LIBADD) \
	$(FEMA_LIBADD) \
	$(SOIL_LIBADD) \
	$(ES_FEMA_LIBADD)


flash_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = FlashLog.hh \
		FlashConfig.hh \
		MDServer.hh \
		MultiMDServer.hh \
		MData.hh \
		FlashServer.hh


EXTRA_DIST = env.sh flash.cfg log.cfg

flashdir = $(bindir)
flash_DATA = env.sh flash.cfg log.cfg

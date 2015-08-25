AUTOMAKE_OPTIONS = foreign

SUBDIRS = mdflow

bin_PROGRAMS = flash_tcp
flash_tcp_SOURCES = \
	FlashTCPConfig.cc \
	MDServer.cc \
	Main.cc 


flash_tcp_CPPFLAGS = -I$(top_srcdir) \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(ES_FEMA_CPPFLAGS)


flash_tcp_LDADD = \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(ES_FEMA_LIBADD) \
	../util/libflash.la


flash_tcp_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = FlashTCPConfig.hh \
		MDServer.hh



EXTRA_DIST = tcp_env.sh.example flash_tcp.cfg.example tcp_log.cfg.example

flash_tcpdir = $(bindir)
flash_tcp_DATA = $(EXTRA_DIST)

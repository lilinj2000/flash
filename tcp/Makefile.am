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
		$(FOAL_CPPFLAGS) \
		$(AIR_CPPFLAGS)


flash_tcp_LDADD = \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(FOAL_LIBADD) \
	$(AIR_LIBADD) \
	../util/.libs/libutil.a


flash_tcp_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = FlashTCPConfig.hh \
		MDServer.hh


EXTRA_DIST = tcp_env.sh.example tcp.cfg.example tcp_log.cfg.example

flash_tcpdir = $(bindir)
flash_tcp_DATA = $(EXTRA_DIST)

AUTOMAKE_OPTIONS = foreign

lib_LTLIBRARIES = libflash.la
libflash_la_SOURCES = MData.cc


libflash_la_CPPFLAGS = -I$(top_srcdir) -I..\
			$(BOOST_CPPFLAGS) \
			$(ES_FEMA_CPPFLAGS)


libflash_la_LIBADD = $(BOOST_LIBADD) \
			$(ES_FEMA_LIBADD)

libflash_la_LDFLAGS = \
	-no-undefined -version-info \
	$(LT_CURRENT):$(LT_REVISION):$(LT_AGE) \
	-release $(LT_RELEASE)

# header files
noinst_HEADERS = FlashLog.hh \
	 	MData.hh


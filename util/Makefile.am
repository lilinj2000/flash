AUTOMAKE_OPTIONS = foreign

noinst_LTLIBRARIES = libutil.la 
libutil_la_SOURCES = Util.cc
libutil_la_CPPFLAGS = -I$(top_srcdir) \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(FOAL_CPPFLAGS) \
		$(AIR_CPPFLAGS)

libutil_la_LIBADD = $(BOOST_LIBADD) \
		    $(SOIL_LIBADD)
		    $(FOAL_LIBADD) \
	            $(AIR_LIBADD)


libutil_la_LDFLAGS = \
	-no-undefined  

# header files
noinst_HEADERS = FlashLog.hh Util.hh



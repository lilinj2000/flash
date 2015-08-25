#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(flash, 0.1, lilinj2000@gmail.com)
AC_CONFIG_SRCDIR([])
#AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE

#AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
LT_INIT
AC_PROG_RANLIB
# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
#AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
LT_RELEASE=0.1
LT_CURRENT=0
LT_REVISION=1
LT_AGE=0
AC_SUBST(LT_RELEASE)
AC_SUBST(LT_CURRENT)
AC_SUBST(LT_REVISION)
AC_SUBST(LT_AGE)

home_3rd=`pwd`/../../3rd
home_es=`pwd`/../../es

dnl boost lib
AC_ARG_WITH([boost],
    [AS_HELP_STRING([--with-boost],
        [home path of the boost, defaults to $home_3rd/boost])],
    [BOOST_HOME="$withval"],
    [BOOST_HOME="$home_3rd/boost"])
AC_SUBST([BOOST_HOME])

BOOST_CPPFLAGS="-I$BOOST_HOME/include -DBOOST_ALL_DYN_LINK"
BOOST_LIBADD="$BOOST_HOME/lib/libboost_log_setup.so \
              $BOOST_HOME/lib/libboost_log.so \
	      $BOOST_HOME/lib/libboost_filesystem.so \
  	      $BOOST_HOME/lib/libboost_program_options.so \
	      $BOOST_HOME/lib/libboost_regex.so \
	      $BOOST_HOME/lib/libboost_thread.so \
	      $BOOST_HOME/lib/libboost_chrono.so \
	      $BOOST_HOME/lib/libboost_date_time.so \
	      $BOOST_HOME/lib/libboost_system.so"
AC_SUBST(BOOST_CPPFLAGS)
AC_SUBST(BOOST_LIBADD)

dnl soil lib
AC_ARG_WITH([soil],
    [AS_HELP_STRING([--with-soil],
        [home path of the soil, defaults to $home_es/soil])],
    [SOIL_HOME="$withval"],
    [SOIL_HOME="$home_es/soil"])
AC_SUBST([SOIL_HOME])

SOIL_CPPFLAGS="-I$SOIL_HOME/include"
SOIL_LIBADD="$SOIL_HOME/lib/libsoil.la"
AC_SUBST(SOIL_CPPFLAGS)
AC_SUBST(SOIL_LIBADD)

dnl es-fema lib
ES_FEMA_HOME=$home_es/fema-v1_01
AC_ARG_WITH([es-fema],
    [AS_HELP_STRING([--with-es-fema],
        [home path of the es-fema, defaults to $ES_FEMA_HOME])],
    [ES_FEMA_HOME="$withval"],
    [ES_FEMA_HOME="$ES_FEMA_HOME"])
AC_SUBST([ES_FEMA_HOME])

ES_FEMA_CPPFLAGS="-I$ES_FEMA_HOME/include"
ES_FEMA_LIBADD="$ES_FEMA_HOME/lib/libfema.la"
AC_SUBST(ES_FEMA_CPPFLAGS)
AC_SUBST(ES_FEMA_LIBADD)

AC_ARG_ENABLE([multi],
    [AS_HELP_STRING([--enable-multi],
        [enable multi support, @<:@default=no@:>@])],
    [case "${enableval}" in
      yes) multi=true ;;
      no)  multi=false ;;
       *) AC_MSG_ERROR([bad value ${enableval} for --enable-multi]) ;;
    esac],
    [multi=false])
AM_CONDITIONAL([MULTI], [test x$multi = xtrue])



AC_OUTPUT([
	Makefile
	util/Makefile
	tcp/Makefile
	tcp/mdflow/Makefile
	multi/Makefile
	multi/mdflow/Makefile])






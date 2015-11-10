#! /bin/sh

home_libs=~/libs
home_app=~/app

if test -d /llj/libs ; then
   home_libs=/llj/libs
fi

if test -d /llj/app ; then
   home_app=/llj/app
fi

deployFlash()
{
    # flash v1_01
    prefix=$home_app/flash-v1_01
    ./configure --prefix=$prefix
    make
    rm -rf $prefix
    make install

    make distclean

    # flash v1_21
    prefix=$home_app/flash-v1_21
    ./configure --prefix=$prefix --with-foal=$home_libs/foal-v1_21
    make
    rm -rf $prefix
    make install

    make distclean

    # flash v1_01_multi
    prefix=$home_app/flash-v1_01_multi
    ./configure --prefix=$prefix --with-foal=$home_libs/foal-v1_01_multi --enable-multi
    make
    rm -rf $prefix
    make install

    make distclean

}

deployFlash

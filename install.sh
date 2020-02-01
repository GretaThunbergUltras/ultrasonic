#!/bin/bash
echo "building sonic.c..."
gcc -shared -Wl,-soname,libsonic -o libsonic.so -fPIC -lwiringPi -lpigpio sonic.c
echo "copying to /usr/local/lib"
cp libsonic.so /usr/local/lib/libsonic.so
echo "setting user rights..."
chmod a+rwx /usr/local/lib/libsonic.so
echo "done!"


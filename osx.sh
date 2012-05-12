#!/bin/bash

rm lib/osx/*
mkdir lib
mkdir lib/osx
clang++ -dynamiclib -arch i386 -D I3D_OS_S3E -D S3E_EDK_USE_DLLS \
  source/generic/atomics.cpp \
  source/generic/atomics_register.cpp \
  -I source/h -I h \
  -I /Developer/Marmalade/6.0/s3e/edk/h \
  -I /Developer/Marmalade/6.0/s3e/h \
  -L /Developer/Marmalade/6.0/s3e/edk/lib/osx \
  -Wl,-u -Wl,__IwMain -framework Foundation \
  -ledk -o lib/osx/libatomics.dylib
cp lib/osx/libatomics.dylib lib/osx/libatomics_d.dylib

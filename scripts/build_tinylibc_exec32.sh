#!/bin/bash

OUT=`realpath ./out`
SRC="*.c"
LIB=`realpath tinylibc`

cd sources
    gcc                       \
        -nostdinc             \
        -nostdlib             \
        -nostartfiles         \
        -I $LIB/include       \
        -I $LIB/include/dummy \
        -o $OUT               \
        $SRC                  \
        -m32                  \
        -L $LIB -l tiny
cd ..
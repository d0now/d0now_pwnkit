#!/bin/bash

OUT="test"
SRC="test.c"
LIB="./tinylibc"

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
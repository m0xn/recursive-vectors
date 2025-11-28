#!/usr/bin/bash

if [[ ! -e build ]]; then
    mkdir build
fi

CC_FLAGS="-Wall -Werror"
g++ src/main.cpp lib/recVector.cpp -o build/main $CC_FLAGS

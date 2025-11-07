#!/usr/bin/bash

CC_FLAGS="-Wall -Werror"
g++ src/main.cpp lib/recVector.cpp -o build/main $CC_FLAGS

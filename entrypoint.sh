#!/bin/sh -l

cmake -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/arm-none-eabi-gnu.cmake -S ./examples/blinky_nucleo -B build -G Ninja
cmake --build build -v

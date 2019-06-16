#!/bin/sh

# Configuration variables
AVR_UPLOADTOOL='avrdude'
AVR_UPLOADTOOL_PORT='usb'
AVR_PROGRAMMER='usbasp'
AVR_MCU='attiny85'
AVR_MCU_SPEED='8000000UL'


SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
BUILD_DIR="$SCRIPT_DIR/build"

mkdir -p $BUILD_DIR
cd $BUILD_DIR

cmake 	-DCMAKE_TOOLCHAIN_FILE=../cmake/avr-gcc-toolchain.cmake \
	-DCMAKE_BUILD_TYPE=Debug \
	-DAVR_UPLOADTOOL="$AVR_UPLOADTOOL" \
	-DAVR_UPLOADTOOL_PORT="$AVR_UPLOADTOOL_PORT" \
	-DAVR_PROGRAMMER="$AVR_PROGRAMMER" \
	-DAVR_MCU="$AVR_MCU" \
	-DAVR_MCU_SPEED="$AVR_MCU_SPEED" \
	..
	#-G "Eclipse CDT4 - Unix Makefiles" -DCMAKE_ECLIPSE_VERSION="4.10" \


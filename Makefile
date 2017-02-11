#
# Makefile for the ulk modules test.
#

CROSS_COMPILE = /ulk/toolchain/CodeSourcery/Sourcery_G++_Lite/bin/arm-none-linux-gnueabi-

all:
	$(CROSS_COMPILE)gcc exotic.c -o all

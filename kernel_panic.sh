#!/bin/bash

# WARNING! This script will almost certainly hang a system, in fact, that is the intention.
# This can be used to test failure modes and recovery mechanisms by inducing a system hang.
# Credit to StackExchange user IW16:
# https://unix.stackexchange.com/a/255937/369944

#check to see if we are root
if [ "$EUID" -ne 0 ]; then
  echo ""
  echo "Please run as root ==>"
  echo ""
  echo "sudo su"
  echo ""
  echo "$0"
  echo ""
  exit
fi

mkdir /tmp/kpanic
cd /tmp/kpanic
mkdir -p /lib/modules/$(uname -r)/build
printf '#include <linux/kernel.h>\n#include <linux/module.h>\nMODULE_LICENSE("GPL");static int8_t* message = "buffer overrun at 0x4ba4c73e73acce54";int init_module(void){panic(message);return 0;}' > kpanic.c
printf "obj-m += kpanic.o\nall:\n\tmake -C /lib/modules/$(uname -r)/build M=$(pwd) modules" > Makefile
make
insmod kpanic.ko

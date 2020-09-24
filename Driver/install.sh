#!/bin/bash

rel=`uname -r`
if [ ! -f GbtLinuxFuncDrv.$rel.ko ]; then
  echo Kernel $rel is not supported
  echo Please contact Gigabyte Software RD \(mark@gigabyte.com\)
  exit
fi

modinfo GbtLinuxFuncDrv.$rel.ko
sudo modprobe wmi
sudo insmod GbtLinuxFuncDrv.$rel.ko
sudo chmod 666 /dev/GbtLinuxFunc
dmesg | tail -n 4 
cat /proc/devices | grep GbtLinuxFunc
ls /dev/GbtLinuxFunc -la


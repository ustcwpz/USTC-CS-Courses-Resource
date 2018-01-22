#!/bin/bash

make
echo make

dd if=/dev/zero of=output/a.img bs=512 count=2880
echo dd if=/dev/zero of=output/a.img bs=512 count=2880
echo
sudo losetup /dev/loop4 output/a.img
echo sudo losetup /dev/loop4 output/a.img
echo
sudo dd if=output/start16.bin of=/dev/loop4 bs=512 count=1
echo sudo dd if=output/start16.bin of=/dev/loop4 bs=512 count=1
echo
sudo dd if=output/myOS.bin of=/dev/loop4 bs=512 seek=1
echo sudo dd if=output/myOS.bin of=/dev/loop4 bs=512 seek=1
echo 
qemu -fda output/a.img -s -S&
echo qemu -fda output/a.img -s -S&
echo
sudo losetup -d /dev/loop4
echo sudo losetup -d /dev/loop4
echo



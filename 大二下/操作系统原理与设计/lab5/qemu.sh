#!/bin/bash

make
echo make

dd if=/dev/zero of=a.img bs=512 count=2880
echo dd if=/dev/zero of=a.img bs=512 count=2880
echo
sudo losetup /dev/loop4 a.img
echo sudo losetup /dev/loop4 a.img
echo
sudo dd if=16.bin of=/dev/loop4 bs=512 count=1
echo sudo dd if=16.bin of=/dev/loop4 bs=512 count=1
echo
sudo dd if=OS.bin of=/dev/loop4 bs=512 seek=1
echo sudo dd if=OS.bin of=/dev/loop4 bs=512 seek=1
echo 
qemu -fda a.img&
echo qemu -fda a.img&
echo
sudo losetup -d /dev/loop4
echo sudo losetup -d /dev/loop4
echo

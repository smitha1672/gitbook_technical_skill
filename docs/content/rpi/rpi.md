## rpi2 module B
[Create a linux kernal dirver](https://www.slideshare.net/raspberrypi-tw/write-adevicedriveronraspberrypihowto)
<br> [NOOBS For Raspberry Pi](http://qdosmsq.dunbar-it.co.uk/blog/2013/06/noobs-for-raspberry-pi/)
<br> SSH client login information.

```text
  Username: pi
  Password: raspberry
```
<br> [Kernal Building - CROSS-COMPILING](https://www.raspberrypi.org/documentation/linux/kernel/building.md)

```text
export KERNEL=kernel7
export ARCH=arm
export CROSS_COMPILE=/home/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf-

# export modules intall path
  export INSTALL_MOD_PATH=/home/mnt/ext4

# For Pi 2, Pi 3, or Compute Module 3:
  cd linux
  KERNEL=kernel7
  make bcm2709_defconfig

# Build and install the kernel, modules, and Device Tree blobs; this step takes a long time
  make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- zImage modules dtbs

# INSTALL DIRECTLY ONTO THE SD CARD
  lsblk
  sdb1 (being the FAT (boot) partition)
sdb2 (being the ext4 filesystem (root) partition.)

  *If it's a NOOBS card, you should see something like this:
  sdb
  sdb1
  sdb2
  sdb5
  sdb6 (being the FAT (boot) partition)
sdb7 (being the ext4 filesystem (root) partition.)
# Mount these first, adjusting the partition numbers for NOOBS cards:
  mkdir mnt/fat32
  mkdir mnt/ext4
  sudo mount /dev/sdb1 mnt/fat32
  sudo mount /dev/sdb2 mnt/ext4
# Next, install the modules:
  sudo make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- INSTALL_MOD_PATH=mnt/ext4 modules_install
# Finally, copy the kernel and Device Tree blobs onto the SD card, making sure to back up your old kernel:
  cp mnt/fat32/$KERNEL.img mnt/fat32/$KERNEL-backup.img
  cp -v arch/arm/boot/zImage /home/mnt/fat32/$KERNEL.img
  cp -v arch/arm/boot/dts/*.dtb /home/mnt/fat32/
                           cp -v arch/arm/boot/dts/overlays/*.dtb* /home/mnt/fat32/overlays/
                           cp -v arch/arm/boot/dts/overlays/README /home/mnt/fat32/overlays/
                           umount mnt/fat32
                           umount mnt/ext4
```

## Environment setup
```text
Docker + ubuntu 16.04 (Refer https://blog.gtwang.org/virtualization/ubuntu-linux-install-docker-tutorial/)
    1. sudo apt-get install docker.io
    2. service docker status
    3. sudo usermod -aG docker smith
    4. docker version
    5. docker pull ubuntu:16.04
    6. docker images(get all container images info)
# create a share folder with host:container folder
    1. sudo docker run -t -i -v /home/smith/project/private_raspi:/home/ ubuntu:16.04 bash
# install packet: 
     apt-get install g++, 
     apt-get install make, 
     apt-get install gawk, 
     apt-get install git-core, 
     apt-get install libncurses5-dev, 
     apt-get install vim, 
     apt-get install wget,
     apt-get install unzip, 
     apt-get install bzip2, 
     apt-get install cpio,
     apt-get install python
     apt-get install bc
     apt-get install device-tree-compiler 
  # docker: create a image (at first time)
      1. docker run -t -i --name="name" container:tag bash
      2. docker export "name" > "name".tar
  # docker: import a docker image
      1. docker import "name:.tar "container name":"tag name"
```
[Build root]
  ref: http://fichugh.blogspot.tw/2016/02/buildroot-study.html

[Buildroot] Get source
    # git clone git://git.buildroot.net/buildroot
    # git checkout 2016.02 -b 2016.02
[Build OS]
    # Reference http://fichugh.blogspot.tw/2016/02/buildroot-study.html
    # Reference file:///home/smith/Downloads/buildroot.pdf

    1. make list-defconfigs(I found more board in board folder)
    2. make raspberrypi2_defconfig
    3. make source(down load all resources)
    4. make menuconfig
        # Filesystem images > tar the root filesystem > Compression
            method選擇是bzip2
        # Bootloaders > 選擇U-boot選項，Board defconfig 輸入「rpi_2」
    5. make 2>&1 | tee build.log

(Result) when you have built done, you will get:
    1. kernel --> zImage
    2. root file system --> rootfs.tar.bz2
    3. device tree blob --> bcm2709-rpi-2-b.dtb
    4. raspberry firmware --> rpi-firmware/*
    5. boot loader--> u-boot.bin

(ERROR 1) 
    /bin/sh: 1: dtc: not found
    scripts/Makefile.lib:322: recipe for target
    'arch/arm/dts/bcm2835-rpi-a-plus.dtb' failed
    make[4]: *** [arch/arm/dts/bcm2835-rpi-a-plus.dtb] Error 127

(#fixed)"sudo apt-get install device-tree-compiler"

## ERROR 2

```text
[7m>>>   Executing post-image script board/raspberrypi2/post-image.sh[27m
file(rootfs.ext4): stat(/home/smith/embedded_linux/buildroot/output/images/rootfs.ext4) 
failed: No such file or directory
hdimage(sdcard.img): could not setup rootfs.ext4
Makefile:720: recipe for target 'target-post-image' failed
make[1]: *** [target-post-image] Error 1
Makefile:79: recipe for target '_all' failed
make: *** [_all] Error 2
```

fixed: board/raspberrypi2/post-image.sh from make menuconfig "system
configuration" Custom scripts to run after creating filesystem images.

Comment: I don't know why root.ext4 cannot be built.
## ERROR 3

```text
make[1]: Entering directory '/home/raspi/buildroot/output/build/uboot-2017.05'
***
*** Can't find default configuration "arch/../configs/raspi2_defconfig"!
***
scripts/kconfig/Makefile:121: recipe for target 'raspi2_defconfig' failed
make[2]: *** [raspi2_defconfig] Error 1
Makefile:478: recipe for target 'raspi2_config' failed
make[1]: *** [raspi2_config] Error 2
make[1]: Leaving directory '/home/raspi/buildroot/output/build/uboot-2017.05'
package/pkg-generic.mk:217: recipe for target
'/home/raspi/buildroot/output/build/uboot-2017.05/.stamp_configured' failed
make: *** [/home/raspi/buildroot/output/build/uboot-2017.05/.stamp_configured]
Error 2
```
<br> fixed: BR2_TARGET_UBOOT_BOARDNAME="rpi_2", if type the other board name, you will build failure
<br> test

```text
# sudo dd if=sdcard.img of=/dev/sdd
# insert micro sd card
# sudo screen /dev/ttyUSB0 115200
# power up rspi2. (I can see bring up status)
```

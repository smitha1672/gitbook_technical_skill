Development Android
====================

環境設定
------

[參考這裡](https://source.android.com/source/initializing)

安裝必要套件

    sudo apt-get install openjdk-8-jdk
    sudo apt-get install git-core gnupg flex bison gperf build-essential \
    zip curl zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 \
    lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z-dev ccache \
    libgl1-mesa-dev libxml2-utils xsltproc unzip

    sudo apt-get install python-pip python-dev build-essential
    python -m pip install pyserial

加入USB檔案建立規則

    wget -S -O - http://source.android.com/source/51-android.txt | sed "s/<username>/$USER/" | sudo tee >/dev/null /etc/udev/rules.d/51-android.rules; sudo udevadm control --reload-rules

額外加入Hikey Board USB ID

    sudo vim /etc/udev/rules.d/51-android.rules

檔案尾端加入以下四行

"OWNER"請記得修改

    # fastboot protocol on Hikey Board
    SUBSYSTEM=="usb", ATTR{idVendor}=="18d1", ATTR{idProduct}=="d00d", MODE="0600", OWNER="User"
    # adb protocol on Hikey Board
    SUBSYSTEM=="usb", ATTR{idVendor}=="18d1", ATTR{idProduct}=="4ee7", MODE="0600", OWNER="User"

存檔完再重新載入規則

    sudo udevadm control --reload-rules

下載repo

    mkdir ~/bin
    PATH=~/bin:$PATH
    curl https://storage.googleapis.com/git-repo-downloads/repo > ~/bin/repo
    chmod a+x ~/bin/repo


因為Android是由很多個git repository所組成的

從最早一百多個repository到現在(Android N)已經有五百多個repository

我們不可能一直執行git clone下載所有的source code

所以透過repo協助下載需要的repository

詳細使用說明請看[這邊](https://source.android.com/source/using-repo)

下載前先設定git user name跟mail

    git config --global user.name "Your Name"
    git config --global user.email "you@example.com"
    
以上的工作只要做一次就好

下載Android source code
----------------------

[參考這裡](https://source.android.com/source/downloading)

建議先開一個mirror

可以提供其他版本做reference 節省硬碟空間

    mkdir aosp_mirror;
    cd aosp_mirror;
    repo init -u https://android.googlesource.com/platform/manifest --mirror -b android-7.1.2_r11;
    repo sync -c -j4;
    
等個半天應該能抓完

接下來再開個目錄放置要編譯的android

For Android 7.1.2

    mkdir aosp_712;
    cd aosp_712;
    repo init -u https://android.googlesource.com/platform/manifest --reference /home/user/aosp_mirror -b android-7.1.2_r11;
    repo sync -c -j4;

For Android 7.1.1

    mkdir aosp_711;
    cd aosp_711;
    repo init -u https://android.googlesource.com/platform/manifest --reference /home/user/aosp_mirror -b android-7.1.1_r40;
    repo sync -c -j4;

For Android 6.0.1

    mkdir aosp_601;
    cd aosp_601;
    repo init -u https://android.googlesource.com/platform/manifest --reference /home/user/aosp_mirror -b android-6.0.1_r79;
    repo sync -c -j4;


注意: "--reference" 參數的路徑要寫剛才建立mirror的目錄, 請用絕對路徑

因為有mirror目錄下的git object可以參照

所以幾乎不用下載直接解開了

下載Graphics binaries

    wget https://dl.google.com/dl/android/aosp/linaro-hikey-20160226-67c37b1a.tgz
    tar zxvf linaro-hikey-20160226-67c37b1a.tgz.tgz
    ./extract-linaro-hikey.sh

編譯Android
----------

    source build/envsetup.sh;
    lunch hikey-userdebug;
    make -j4;

碰到out of memory問題

1. 可以嘗試修改編譯參數

    export ANDROID_JACK_VM_ARGS="-Dfile.encoding=UTF-8 -XX:+TieredCompilation -Xmx4096m"

2. 針對libart先build
    make libart

編譯Android6.0遇到JAVA版本不match

    export EXPERIMENTAL_USE_JAVA8=true

下載Kernel
---------
    cd <AOSP_ROOT>
    git clone https://android.googlesource.com/kernel/hikey-linaro
    cd hikey-linaro
    git checkout -b hikey_4.4 664e6d0

編譯Kernel
---------
    cd hikey-linaro
    make ARCH=arm64 hikey_defconfig
    make ARCH=arm64 CROSS_COMPILE=<AOSP_ROOT>/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/aarch64-linux-android- -j4

## AOSP6 Trouble Shooting
### ERROR
```text
make: *** [out/host/common/obj/JAVA_LIBRARIES/guavalib_intermediates/javalib.jar] Error 41
```
+ Fix: Add PPA for OpenJDK7
<br>
```text
  $ apt-get install software-properties-common python-software-properties
  $ apt remove openjdk-* icedtea-* icedtea6-*
  [oracle openjdk ppa source]
  $ add-apt-repository ppa:openjdk-r/ppa
  $ apt-get update
  $ apt-get install openjdk-7-jdk
  [oracle java jdk ppa source]
  $ add-apt-repository ppa:webupd8team/java
  $ apt-get update
  [JDK6]
  $ apt-get install oracle-java6-installer
  [JDK 7]
  $ apt-get install oracle-java7-installer

  Ref:
    https://groups.google.com/forum/#!topic/android-building/WbFF6Zk8dqY
    http://oopsmonk.github.io/blog/2016/06/07/android-build-error-on-ubuntu-16-04-lts
    http://www.cnblogs.com/bluestorm/p/5677625.html

  PS: If you have other java version in system, make sure your java version is correct.
  sudo update-alternatives --config java
  sudo update-alternatives --config javac
  sudo update-alternatives --config javadoc
  sudo update-alternatives --config javap
  sudo update-alternatives --config javaws
  sudo update-alternatives --config jar
```

### ERROR
```text
clang: error: linker command failed with exit code 1 (use -v to see invocation)
build/core/host_shared_library_internal.mk:51: recipe for target 'out/host/linux-x86/obj32/lib/libart.so' failed
make: *** [out/host/linux-x86/obj32/lib/libart.so] Error 1
```
+ FIX:

```text
fix:
./Android.common_build.mk
ifneq ($(WITHOUT_HOST_CLANG),true)
  # By default, host builds use clang for better warnings.
  ART_HOST_CLANG := false
endif

build/core/base_rules.mk:559: recipe for target 'out/host/linux-x86/framework/jack.jar' failed
USER: unbound variable

Cause: Build with a docker system
fix: Define the USER environment variable (not set by default), e.g. export USER=$(whoami)
```

## AOSP7 Trouble Shooting



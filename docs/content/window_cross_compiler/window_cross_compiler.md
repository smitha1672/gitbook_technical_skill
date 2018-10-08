## Window Cross Compiler

I develop a RST3111 project with MinGW, windows.lnk, gccenv.bat and xtensa xplorer.

+ [MinGW](http://www.mingw.org/)
It is used to similar linux command line enviorment, and building code by make.


+ windows.lnk
It is in order to create a command line environment for building code manipulation.

```text
target: %windir%\system32\cmd.exe /K D:\src\XTENSA_SDK\gccenv.bat
start: w:\workspace\project
```

+ gccenv.bat
It is in order setup environment path

```text
@echo off
set PATH=C:\MinGW\bin;%PATH%
set PATH=C:\MinGW\msys\1.0\bin;%PATH%
set PATH=C:\usr\xtensa\XtDevTools\install\tools\RF-2015.3-win32\XtensaTools\bin\;%PATH%
set PATH=C:\Program Files (x86)\Notepad++;%PATH%
set PATH=C:\Program Files (x86)\Tensilica\Xtensa OCD Daemon 11.0.3;%PATH%
set PATH=C:\Program Files (x86)\Source Insight 3\;%PATH%
set dev_folder=D:\src\realtek_beta\cwm_dev\dev_nano\gitLab_Chre\chre\firmware
title XTENSA_SDK
```

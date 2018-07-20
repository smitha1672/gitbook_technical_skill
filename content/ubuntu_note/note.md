# Started

##  awk

```text
awk '{print $1}' filename.txt: simply output
awk '{print $1,$2}' filename.txt: ouput more items
awk '/<pattern>/{print $1,$2}' filename: if pattern is matched, output $1 and $2
```

## dd

```text
#create a 0x00 file:
$ dd if=/dev/zero bs=1 of=/tmp/file bs=2M count=2000
 #bs: block size, 1次讀取與寫入 BYTES 位元組的資料，此選項會覆蓋 ibs 與 obs 的設定
  count=N：只處理 N 個輸入區塊，每個區塊的大小為 ibs。

#padding zero bytes into a end of file
$ dd if=/dev/zero bs count=2148 >> file
  
#create a 0xff file:
$ dd if=/dev/zero bs=1k count=100 | tr "\000" "\377" >paddedFile.bin
```

## vimgrep

```text
ref.: https://blog.easwy.com/archives/advanced-vim-skills-quickfix-mode/
As follows:
    :vim[grep][!] /{pattern}/[g][j] {file} ..
  Recursive search:
    :vimgrep /dostuff()/j ../**/*.c
  Dotfiles:
    :vimgrep /pattern/ ./.*
  :cw
  :copen
    These commands all fill a list with the results of their search.
    "grep" and "vimgrep" fill the "quickfix list",
    which can be opened with :cw or :copen
  
  ref.: https://blog.csdn.net/zqiang_55/article/details/30715961
  vimgrep /匹配模式/[g][j] 要搜索的文件/范围
  g：表示是否把每一行的多个匹配结果都加入
  j：表示是否搜索完后定位到第一个匹配位置

  vimgrep /pattern/ %           在当前打开文件中查找
  vimgrep /pattern/ *           在当前目录下查找所有
  vimgrep /pattern/ **          在当前目录及子目录下查找所有
  vimgrep /pattern/ *.c         查找当前目录下所有.c文件
  vimgrep /pattern/ **/*        只查找子目录

  cn                            查找下一个
  cp                            查找上一个
  copen                         打开quickfix
  cw                            打开quickfix
  cclose                        关闭qucikfix
  help vimgrep                  查看vimgrep帮助

  ref.: https://blog.csdn.net/icbm/article/details/71036168
  files 参数举例：
  % 表示在当前缓冲区文件中查找。
  *.cpp 表示在当前目录中的 .cpp 文件中搜索。
  **/*.cpp 表示在当前目录及子目录中 .cpp 文件中搜索。
  **/*.cpp **/*.h 表示在当前目录及子目录中 .cpp、.h 文件中搜索。
```

## vimdiff

```text
Keyboard Shortcuts:
  do - Get changes from other window into the current window.
  dp - Put the changes from current window into the other window.
  ]c - Jump to the next change.
  [c - Jump to the previous change.
  Ctrl W + Ctrl W - Switch to the other split window.

  If you load up two files in splits (:vs or :sp), you can do 
  :diffthis 

  on each window and achieve a diff of files that were already loaded in buffers
  :diffoff can be used to turn off the diff mode.

  "update diff"
  :diffupdate

  zo: 顯示隱藏 / 折疊的文字區塊
  zc: 將目前游標所在位置文字區塊隱藏 / 折疊
  zr: 將兩份文件都完全折疊
  
  reference linking:
  http://vimdoc.sourceforge.net/htmldoc/diff.html
```

## VIM

```text
"import .vimrc file":
:so ~/.vimrc
  
"show binary file":
:%!xxd
  
"copy more lines in register, and then paste to a place"
  1. "V" is for a section would be like to copy.
  2. "kyy
  3. "kp"
"replace from string.a to string.b"
  :1,$s/string.a/string.b/gc

ref.: https://www.openfoundry.org/tw/tech-column/2383-vim--buffers-and-windows
編輯緩衝區 (Buffers)
$ vim file1 file2 file3

:buffers (:ls or :files)
1 %a   "file1"                        line 1
2      "file2"                        line 0
3      "file3"                        line 0

跳至特定編輯緩衝區可使用 :[N]buffer 命令，如:
:2buffer
or
:buffer 2

若要新增其他檔案進編輯緩衝區，可使用 :badd 命令:
:badd path/to/file4
```

## Zip/ Unzip

```text
$ unzip -u test.zip
$ unzip -j test.zip 
    #-j: it only unzip files that doesn't include directory
$ unzip test.zip -d mydir 
    #-d: it means destnation directory
$ unzip -l test.zip 
    #-l: show achive's content

Command format. The basic command format is:
$ zip options archive inpath inpath ...
  
# archive all the source files in the current directory and its subdirectories:
$ find ./out/mt2523_watch/watch_ref_design -maxdepth 1 -type f -print | \
zip -j source -@
$ find ./chre/firmware -type f -name "os.checked.*" -print | \
zip -j w2_cmh1000_fw_v15_1804Bxxx -@
    #-j: junk-path
```

## Ubuntu Update

```bash
$ sudo apt-get update
$ sudo apt-get -y dist-upgrade
$ sudo apt-get clean
$ sudo apt-get autoremove
```

## Ubuntu uninstall

```text
$ sudo apt-get remove texlive-full
#但由於先前安裝此套件，會一併自動安裝相依套件（dependencies），所以需要再用 autoremove 清理。
$ sudo apt-get autoremove
or
$ sudo apt-get remove --auto-remove

#但是這樣還不夠乾淨，因為預設的 remove 行為，會保留一些設定檔之類的遺物。
所以需要用 purge 的方式移除。針對單一套件使用 purge 方式徹底移除：
$ sudo apt-get purge texlive-full
or
$ sudo apt-get remove --purge texlive-full

ref.
http://blog.lyhdev.com/2013/01/ubuntu-linux-apt-get.html

```

## Others

 Copy folder structure \(sans files\) from one location to another

```bash
find . -type d > dirs.txt #to create the list of directories, then
xargs mkdir -p < dirs.txt #to create the directories on the destination.
```

## Docker

> [https://blog.longwin.com.tw/2017/01/docker-learn-initial-command-cheat-sheet-2017/](https://blog.longwin.com.tw/2017/01/docker-learn-initial-command-cheat-sheet-2017/)

> [https://blog.gtwang.org/virtualization/ubuntu-linux-install-docker-tutorial/](https://blog.gtwang.org/virtualization/ubuntu-linux-install-docker-tutorial/)

```text
Docker 抓取 Image
docker pull ubuntu # 抓所有 ubuntu image 回來, tag 可於後面附加上去
docker pull ubuntu:16.04 # 只抓取 Ubuntu 16.04 的 Image
docker pull debian:jessie
docker pull debian:latest # library/debian - Docker Hub，latest 只會抓最新版 (Debain Docker 官方版)
docker pull ubuntu:latest # library/ubuntu - Docker Hub

#如果要匯出本地某個容器，可以使用 docker export 命令。
$ sudo docker ps -a
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS                    PORTS               NAMES
7691a814370e        ubuntu:14.04        "/bin/bash"         36 hours ago        Exited (0) 21 hours ago                       test

$ sudo docker export 7691a814370e > ubuntu.tar

#可以使用 docker import 從容器快照檔案中再匯入為映像檔，例如
$ cat ubuntu.tar | sudo docker import - test/ubuntu:v1.0

# docker: create a image (at first time)
      1. docker run -t -i --name="name" container:tag bash
      2. docker export "name" > "name".tar
 # docker: import a docker image
      1. docker import "name:.tar "container name":"tag name"
 sudo docker run -itv /home/smith/workspace/project:/home/mt2523 ubuntu/14.04:linkit_gfx bash

```

##  How To Install Node.js on Ubuntu 16.04

> [how-to-install-node-js-on-ubuntu-16-04](https://www.digitalocean.com/community/tutorials/how-to-install-node-js-on-ubuntu-16-04)

## How to Install gitbook on Ubuntu 16.04

> [how-to-install-node-js-on-ubuntu-16-04; ](https://blog.csdn.net/lj1404536198/article/details/78423671)
> [git-book-start](http://samwhelp.github.io/blog/read/platform/gitbook/start/)

## Trouble Shooting

```text
#sudo must be owned by uid 0 and have the setuid bit set

You shouldn’t have a /usr/local/bin/sudo, 
that’s what’s breaking things (not the password change). Move it out of the way:

/usr/bin/sudo mv /usr/local/bin/sudo{,2}
and then tell your shell about it:

hash -r
That will restore the sudo functionality you’re used to.

shareimprove this answer
```

```text
#Screen needs mode 777 with systemd service
The directory needs full permissions to read, write, and execute.
You can do this command chmod -R 777 /var/run/screen

Which will recursively change all folders/files permissions to 777, 
though typically less secure.
You can also run sudo chown -R $USER:$USER /var/run/screen

This will allow a typical user/or group full access, and will be more secure
```

#### 

#### 




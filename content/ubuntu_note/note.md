## VIM
### operation
+ **:so ~/.vimrc**: Import vimrc setting
+ **:%!xxd**: show binary file
+ copy more lines in register, and then paste to a place
  example:
  1. **V** is for a section would be like to copy.
  2. **"kyy** copy the section in register
  3. **"kp"** paste the section to your destnation place
+ **:line_number,$s/string.a/string.b/gc**" Replace from string.a to string.b

### [vim buffers and windows](https://www.openfoundry.org/tw/tech-column/2383-vim--buffers-and-windows)
open a few files to vim buffers
```bash
$vim file1 file2 file3
```
**:ls** - it show as below
```text
:buffers (:ls or :files)
1 %a   "file1"                        line 1
2      "file2"                        line 0
3      "file3"                        line 0
```
**:[N]buffer** - Jump to particular file
```text
:2buffer or :buffer 2
```
**:badd** - Add a file to buffer
```text
:badd path/to/file4
```


## ZIP/ UNZIP
#### unzip
[Linux man page](https://linux.die.net/man/1/unzip)
```bash
unzip letters
```
To use unzip to extract all members of the archive letters.zip into the **current directory** and **subdirectories**, creating any subdirectories as necessary

```bash
unzip -j letters
```
To extract all members of letters.zip into **the current directory only**

```bash
unzip -tq letters
```
To test letters.zip, **printing only a summary message indicating** whether the archive is OK or not:

```bash
unzip -tq \*.zip
```
To test all zipfiles in **the current directory**, printing only the summaries:


To do a singly quiet listing:
```bash
unzip -l file.zip #To do a singly quiet listing
unzip -ql file.zip #To do a doubly quiet listing
```

## Ubuntu Update

```bash
$ sudo apt-get update
$ sudo apt-get -y dist-upgrade
$ sudo apt-get clean
$ sudo apt-get autoremove
```

## Ubuntu Uninstall

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

## Samba

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




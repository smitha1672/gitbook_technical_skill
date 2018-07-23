## Applications Installation
openssh-server
vim, .vimrc, vim color-minimalist.vim
git .gitconfig
screen, .screenrc
docker
samba-server

## VIM
### Operation
+ **:so ~/.vimrc**: Import vimrc setting
+ **:%!xxd**: show binary file
+ copy more lines in register, and then paste to a place
  example:
  1. **V** is for a section would be like to copy.
  2. **"kyy** copy the section in register
  3. **"kp"** paste the section to your destnation place
+ **:line_number,$s/string.a/string.b/gc**" Replace from string.a to string.b
+ [vim buffers and windows](https://www.openfoundry.org/tw/tech-column/2383-vim--buffers-and-windows)
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
### .vimrc instance
```text
set softtabstop=2
" auto change line
set wrap
" set background
set background=dark
" set UTF-8 encoding
set enc=utf-8
set fenc=utf-8
set termencoding=utf-8
" disable vi compatibility (emulation of old bugs)
set nocompatible
" use indentation of previous line
set autoindent
" use intelligent indentation for C
set smartindent
" configure tabwidth and insert spaces instead of tabs
set tabstop=2        " tab width is 4 spaces
set shiftwidth=2     " indent also with 4 spaces
set expandtab        " expand tabs to spaces
" wrap lines at 120 chars. 80 is somewaht antiquated with nowadays displays.
"set textwidth=80
" turn syntax highlighting on
set t_Co=256
syntax on
" colorscheme wombat256
" turn line numbers on
"set number
" highlight matching braces
set showmatch

"link ctags
"let Tlist_Ctags_Cmd='/usr/bin/ctags'

"smith add
"if &diff
  colorscheme minimalist
"endif

" High light unwanted spaces in end of line
"highlight ExtraWhitespace ctermbg=darkred guibg=darkcyan
highlight ExtraWhitespace ctermbg=darkred guibg=darkcyan
autocmd BufEnter * if &ft != 'help' | match ExtraWhitespace /\s\+$/ | endif
autocmd BufEnter * if &ft == 'help' | match none /\s\+$/ | endif
```

## Screen
[screen installation and intance](https://blog.gtwang.org/linux/screen-command-examples-to-manage-linux-terminals/)

### .screensrc instance
```text
# Start message
startup_message off

# Set hardstatus always on
hardstatus alwayslastline " %-Lw%{= Bw}%n%f %t%{-}%+Lw %=| %M %d %0c:%s "

# Set default encoding using utf8
defutf8 on

# Refresh the display when exiting programs
altscreen on

# Dynamic title
shelltitle '$ |bash'

# Disable vbell
vbell off

# Keboard binding
# bind F11 to move to previous window
bindkey -k F1 prev
# bind F12 to move to next window
bindkey -k F2 next
# bind Alt`~= to screen0~12
bindkey "^[`" select 0
bindkey "^[1" select 1
bindkey "^[2" select 2
bindkey "^[3" select 3
bindkey "^[4" select 4
bindkey "^[5" select 5
bindkey "^[6" select 6
bindkey "^[7" select 7
bindkey "^[8" select 8
bindkey "^[9" select 9
bindkey "^[0" select 10
bindkey "^[-" select 11
bindkey "^[=" select 12
# bind F7 to detach screen session (to background)
bindkey -k k7 detach
# bind F8 to kill current screen window
bindkey -k k8 kill
# bind F9 to create a new screen
bindkey -k k9 screen
# bind F10 to rename current screen window
bindkey -k k; title
# ALT+S make a separate  window
bindkey "^[s" split
# ALT+f swith separate window
bindkey "^[f" focus
# ALT+q leave a separate window
bindkey "^[q" only

```

## Docker
Refer as:
[Ubuntu Docker Install](https://blog.gtwang.org/virtualization/ubuntu-linux-install-docker-tutorial/), [Learn Docker](https://blog.gtwang.org/virtualization/ubuntu-linux-install-docker-tutorial/) and [Docker Command Line](https://docs.docker.com/engine/reference/commandline/docker/)

+ **Docker Install**
> Install
```bash
sudo apt-get install docker.io
```
> Serve Checking
```bash
service docker status
```
> Add my account to docker group
```bash
sudo usermod -aG docker smith
```
> Checking Verion
```bash
docker version
```

+ Docker pull **ubuntu 16.04 or latest**
```bash
docker pull ubuntu:16.04 #or ubuntu:latest
```

+ List images
```bash
docker images
```
```text
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
ubuntu              16.04               e13f3d529b1a        4 days ago          115 MB
```

+ Export/Import a container
> List contains
```text
$ sudo docker ps -a
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS                    PORTS               NAMES
7691a814370e        ubuntu:14.04        "/bin/bash"         36 hours ago        Exited (0) 21 hours ago                       test
```
> export the container
```bash
sudo docker export 7691a814370e > ubuntu.tar #ubuntu.tar is a example
```
> import a image file to image
```bash
 docker import ubuntu.tar unbuntu16.04:v1.0 # ubuntu.tar unbuntu16.04:v1.0 is a example
```

+ Run a image
```bash
sudo docker run -itv /home/smith/workspace/project:/home/mt2523 ubuntu/14.04:linkit_gfx bash
# /home/smith/workspace/project meaning is local directory.
# /home/mt2523 meaning is container directory
# -v: if local directory doest not exist, "-v" is able to remove
```

## Gitbook
You have to install **Node.js**, **npm**, **gitbook**
+ 2 reference URLs:
[how to install node.js on ubuntu 16.04:Native](https://www.digitalocean.com/community/tutorials/how-to-install-node-js-on-ubuntu-16-04)
[git-book-start](http://samwhelp.github.io/blog/read/platform/gitbook/start/)

If you want a **pdf** file, you have to install **calibre**
How to edit [Markdown](https://markdown.tw/#em)
Preview your [MD file](https://stackedit.io/app#)

## Samba
Refer as:
[samba setting on Ubuntu](https://www.arthurtoday.com/2015/04/ubuntu-server-share-folder-samba.html) and [samba directory on Windows](https://noob.tw/samba/)

+ **Samba setting on Ubuntu**
> Install
```bash
sudo apt-get install samba
```
> Add a samba user
```bash
sudo adduser smbuser --shell /bin/false #smbusr can be anyone, Smith
```
> Add a samba user password
```bash
sudo smbpasswd -a smbuser
```
> Setting samba configuration **/etc/samba/smb.conf** 檔案，然後，在檔案的尾巴加入下面這幾行後存檔離開。
```bash
[public]              #"public" 名稱可以自行變更
path = /home/smbuser  #這個是要分享的資料夾路徑
available = yes
valid users = smbuser #這個是可以使用這個分享資料夾的使用者，要具有 path 所指定的路徑的權限才行
read only = no
browseable = yes
public = yes
writable = yes
```
> Restart Samba serve
```bash
sudo service smbd restart
```
+ **Other Samba Configuration**
**/etc/samba/smb.conf**:
首先先找到設定檔裡面的 **workgroup**, 大約在29行附近，把 workgroup
設成和Windows 系統的一樣(可以到控制台\系統及安全性\系統查看)。
**Change this to the workgroup/NT-domain name your Samba server will part of**,
**workgroup = NOOBTW**有關安全性問題，預設 Samba 會使用 Linux 帳號的密碼，
一般來說會建議保持原設定即可；如果要關掉 Samba 的認證，可以在裡面加上：
**security = share** 上面大概是 Samba 的一些基本測試，重頭戲在下面，
如何設定要分享的資料夾？首先我們以**www**資料夾為例，直接將這段放在**smb.conf**
的最下面即可：
```text
[www]
comment = www
path = /var/www
browseable = yes
read only = no
create mask = 777
directory mask = 777
```
+ [www] 指的是要分享的資料夾的名稱，comment 則是描述，path 是 Linux 資料夾的路徑，
browseable 是可否瀏覽，read only 是是否唯讀，剩下兩個 mask 則是檔案預設的權限。
最後請離開 smb.conf，我們要設定可以使用 Samba 的用戶。

+ **Samba setting on Windows**  <br>
As Below:  <br>
![SettingOnWindows](samba_setting_windows.jpg)

## Ubuntu Update
```bash
sudo apt-get update
sudo apt-get -y dist-upgrade
sudo apt-get clean
sudo apt-get autoremove
```

## Ubuntu Uninstall
Remove **texlive-full**
```bash
sudo apt-get remove texlive-full
```
但由於先前安裝此套件，會一併自動安裝相依套（dependencies),
所以需要再用**autoremove**清理。

```bash
sudo apt-get autoremove #or
sudo apt-get remove --auto-remove
```
但是這樣還不夠乾淨，因為預設的 remove 行為，會保留一些設定檔之類的遺物。
所以需要用 purge 的方式移除。針對單一套件使用 purge 方式徹底移除：
```bash
sudo apt-get purge texlive-full #or
sudo apt-get remove --purge texlive-full
```
[ref.](http://blog.lyhdev.com/2013/01/ubuntu-linux-apt-get.html)

## Trouble Shooting
**sudo must be owned by uid 0 and have the setuid bit set**  <br>
You shouldn’t have a /usr/local/bin/sudo,
that’s what’s breaking things (not the password change). Move it out of the way:
```bash
/usr/bin/sudo mv /usr/local/bin/sudo{,2}
```
and then tell your shell about it:
```bash
hash -r
```
That will restore the sudo functionality you’re used to. shareimprove this answer

**Screen needs mode 777 with systemd service**  <br>
The directory needs full permissions to read, write, and execute.
You can do this command
```bash
chmod -R 777 /var/run/screen
```
Which will **recursively** change all folders/files permissions to 777,
though typically less secure.
You can also run sudo
```bash
chown -R $USER:$USER /var/run/screen
```
This will allow a typical user/or group full access, and will be more secure

####

####




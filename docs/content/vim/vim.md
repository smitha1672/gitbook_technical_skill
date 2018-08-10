## VIM
### Installation
```bash
sudo apt-get install vim
```
<br>[\.vimrc Instance](https://github.com/smitha1672/note/blob/master/rc/.vimrc)

### Open vim

```text
# 開啟該程式中的所有原始檔, 並且將顯示位置停留在 main fucntion
vi +/main *.h *.c

# open a few files to vim buffers
```bash
vim file1 file2 file3
```

```

#### Meta Mode (type ESC)
```text
e/E - 將cursor移到字尾.
b/E - 將cursor移到字首
( - 將cursor移到上一句子開頭
) - 將cursor移到下一句子開頭
{ - 將cursor移到上一個段落開頭
} - 將cursor移到下一個段落開頭
I - 將文字插入到cursor position
D/ d$ - After cursor position, End of content is deleted on one line.
d0 - Before cursor position, Start of content is deleted on one line.
U - 取消自上次移動到目前行以來所做的所有操作
. - 將操作重覆執行 (輸入O > 打字 > 輸入.)
M - 將cursor移到screen 的中間行.
L - 將cursor移到screen 的最底行.
```

```text
# Copy more lines in register, and then paste to a place
1. ctrl + V - It is for a section would be like to copy.
2. shift + " + ay - "ay" copies the section in register
3. shift + " + ap - "ap" pastes the section to your destnation place
```

### Command Mode (type :)
```text
# Import .vimrc setting
:so ~/.vimrc
```
```text
# Show binary file
:%!xxd
```
```text
# Replace from string.a to string.b
:[range]s/string.a/string.b/gc #[range] is able be [line.start, line.end]

# 每行的行首都添加一个字符串
:%s/^/要插入的字符串

#每行的行尾都添加一个字符串
:%s/$/要插入的字符串

# 替換以word開始的單字.
:%s/\<buf/stat_buf/g

# 寫新檔名
:w test.c

# 語法反白指令
:syntax on(off)
```

[vim buffers and windows](https://www.openfoundry.org/tw/tech-column/2383-vim--buffers-and-windows)
```text
# Is showes as below
:ls

:buffers (:ls or :files)
1 %a   "file1"                        line 1
2      "file2"                        line 0
3      "file3"                        line 0

# Jump to particular file
:[N]buffer

For instance
:2buffer or :buffer 2

# Add a file to buffer
:badd path/to/file4
```

## vim grep
<br>[ref.1 link](https://blog.easwy.com/archives/advanced-vim-skills-quickfix-mode/)
<br>[ref.2 link](https://blog.csdn.net/zqiang_55/article/details/30715961)
<br>
```text
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

vimgrep /匹配模式/[g][j] 要搜索的文件/范围
g：表示是否把每一行的多个匹配结果都加入
j：表示是否搜索完后定位到第一个匹配位置

vimgrep /pattern/ %           在当前打开文件中查找
vimgrep /pattern/ *           在当前目录下查找所有
vimgrep /pattern/ **          在当前目录及子目录下查找所有
vimgrep /pattern/ *.c         查找当前目录下所有.c文件
vimgrep /pattern/ **/*        只查找子目录

files 参数举例：
% 表示在当前缓冲区文件中查找。
*.cpp 表示在当前目录中的 .cpp 文件中搜索。
**/*.cpp 表示在当前目录及子目录中 .cpp 文件中搜索。
**/*.cpp **/*.h 表示在当前目录及子目录中 .cpp、.h 文件中搜索。
```

```text
cn                            查找下一个
cp                            查找上一个
copen                         打开quickfix
cw                            打开quickfix
cclose                        关闭qucikfix
help vimgrep                  查看vimgrep帮助
```

#
# VIM
## Installation
```bash
sudo apt-get install vim
```
<br>[\.vimrc Instance](https://github.com/smitha1672/note/blob/master/rc/.vimrc)

## [Simple commands to remove unwanted whitespace](http://vim.wikia.com/wiki/Remove_unwanted_spaces)

```text
:%s/\s\+$//e
```

## [Highlight Unwanted Spaces](http://vim.wikia.com/wiki/Highlight_unwanted_spaces)

```text
" Show all tabs:
/\t

" Show trailing whitespace:
/\s\+$

" Show trailing whitespace only after some text (ignores blank lines):
/\S\zs\s\+$

" Show spaces before a tab:
/ \+\ze\t
```

## Search patterns
[linking](http://vim.wikia.com/wiki/Search_patterns)

+ To convert each tab in the file to two spaces

```text
:1,$s/\t/  /g
\t: meaning TAB
\r: meaning newline
```
+ Change only whole words exactly matching 'foo' to 'bar'; ask for confirmation.

```text
:%s/\<foo\>/bar/gc
```
## Search and replace
[linking](http://vim.wikia.com/wiki/Search_and_replace)

```text
# 每行的行首都添加一个字符串
:%s/^/要插入的字符串

#每行的行尾都添加一个字符串
:%s/$/要插入的字符串

# 替換以word開始的單字.
:%s/\<buf/stat_buf/g
```

## Delete all line containing a pattern
[linking](http://vim.wikia.com/wiki/Delete_all_lines_containing_a_pattern)

## Manipulation

+ How can I reload all buffers at once?

```text
See :help bufdo for what you want to do. It will execute a command in each buffer in the buffer list. For example:

:bufdo e
You may also want to look at :help noconfirm to disable the confirmation dialog before issueing the  bufdo command

:set noconfirm
and reenabling it after the bufdo command.

:set confirm
```

+ Switching case of characters

```text
You can change the case of text:

g~: Toggle case "HellO" to "hELLo"
gU: Uppercase "HellO" to "HELLO"
gu: Lowercase "HellO" to "hello"
Alternatively, you can visually select text then press ~ to toggle case, or U to convert to uppercase, or u to convert
to lowercase.
```

+ 開啟該程式中的所有原始檔, 並且將顯示位置停留在 main fucntion

```bash
vi +/main *.h *.c
```

+ open a few files to vim buffers

```bash
# simple example
vim file1 file2 file3
# advance example for C
files=$(find ./ -type -name "*.c" | xargs)
vim $files
# for more type files
file=$(find . -type f \( -name "*.c" -or -name "*.h" \) | xargs)
vim $file
```

+  Moving Around

```text
w: Move forward to the beginning of a word.
3w: Move forward three words.
W: Move forward a WORD (any non-whitespace characters).
3b: Move backward three words.
$: Move to the end of the line.
0: Move to the beginning of the line.
^: Move to the first non-blank character of the line.
10j: Jump forward 10 lines
k: Jump backward one line.
10k: Jump backward 10 lines.
10<PageUp> or 10<CTRL-B> : Move 10 pages up.
5<PageDown> or 5<CTRL-F>: Move 5 pages down.
G: Jump to end of file.
1G: Jump to beginning of file (same as gg).
50G: Jump to line 50.
mx: Set mark x at the current cursor position.
'x: Jump to the beginning of the line of mark x.
`x: Jump to the cursor position of mark x.
'': Return to the line where the cursor was before the latest jump. (Two single quotes.)
``: Return to the cursor position before the latest jump (undo the jump). (Two back ticks. This is above the Tab key on some keyboards.)
'.: Jump to the last-changed line.
 %:  Jump to corresponding item, e.g. from an open brace to its matching closing brace. See Moving to matching braces for  more.
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

+ Copy more lines in register, and then paste to a place

```text
1. ctrl + V - It is for a section would be like to copy.
2. shift + " + ay - "ay" copies the section in register
3. shift + " + ap - "ap" pastes the section to your destnation place
```

+  Command Mode (type :)

```text
# Import .vimrc setting
:so ~/.vimrc
```
```text
# Show binary file
:%!xxd
```

```text
# 寫新檔名
:w test.c

# 語法反白指令
:syntax on(off)
```

+ [vim buffers and windows](https://www.openfoundry.org/tw/tech-column/2383-vim--buffers-and-windows)

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

+ vim grep
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

## vimdiff

+ Open/Close a compare by:

```text
]c               - advance to the next block with differences
[c               - reverse search for the previous block with differences
do (diff obtain) - bring changes from the other file to the current file
dp (diff put)    - send changes from the current file to the other file
zo               - unfold/unhide text
zc               - refold/rehide text
zr               - unfold both files completely
zm               - fold both files completely
:diffupdate after you're made changed
:windo diffthis # Open
:windo diffoff # Close
:%diffput
:%diffget
```

## Tag list
+ Installation
Tag list is able to dowload from the [linking](https://sourceforge.net/projects/vim-taglist/files/) and refer as
[instance] (http://eeepage.info/tag-vim-source-insight/)

```text
$ sudo apt-get install exuberant-ctags
```

+ manipulation

```text
$ ctags -R -h ".h.c...etc"
# CTRL + ] :go to defintion
# CTRL + t :go to back
```

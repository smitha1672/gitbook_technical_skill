#
## Shell Script
+ variable

```bash
myname="OLS3"
echo Hi${myname}kkkk  #有其他字申, 需用${XXX} 隔開
```
+ command and variable

```bash
fc=$(cat /etc/password)
echo "$fc"
```
+ if

```bash
if [ -z $1 ]; then
  echo "if \$1 is empty
fi

if [ -n $1 ]; then
  ehco "if \$1 is not empty
fi
```
### 基礎正規表示法
<br> [reference link](https://dywang.csie.cyut.edu.tw/dywang/linuxProgram/node33.html)
```text
^word 待搜尋的字串(word)在行首。
#範例：grep -n '^#' re.txt
搜尋行首為 # 開始的那一行。
```
```text
word$ 待搜尋的字串(word)在行尾。
#範例：grep -n '!$' re.txt
將行尾為 ! 的那一行列印出來。
```
```text
. 代表『任意一個』字符，一定是一個任意字符。
#範例：grep -n 'e.e' re.txt
搜尋的字串可以是 (eve)(eae)(eee)(e e), 但不能僅有 (ee).
亦即e與e中間"一定"僅有一個字元,而空白字元也是字元.
```
```text
\ 跳脫字符，將特殊符號的特殊意義去除。
#範例：grep -n \' re.txt
搜尋含有單引號 ' 的那一行。
```
```text
\{n,m\} 連續 n 到 m 個的『前一個 RE 字符』
若為 \{n\} 則是連續 n 個的前一個 RE 字符，
若是 \{n,\} 則是連續 n 個以上的前一個 RE 字符。
#範例：grep -n 'go\{2,3\}g' re.txt
在 g 與 g 之間有 2 個到 3 個的 o 存在的字串，亦即 (goog)(gooog)
```
```text
[ ] 在 [ ] 當中『謹代表一個待搜尋的字元』
#範例：grep -n 'g[ld]' re.txt
搜尋含有 (gl) 或 (gd) 的那一行

#範例：grep -n '[0-9]' re.txt
搜尋含有任意數字的那一行。
在字元集合 [ ] 中的減號 - 是代表兩個字元之間的所有連續字元。
[^]：^ 在 [ ] 內時， 代表的意義是『反向選擇』

#範例：grep -n 'oo[^t]' re.txt
搜尋的字串可以是 (oog) (ood) 但不能是 (oot)。
```

## getopts
<br> [reference link](https://stackoverflow.com/questions/16483119/an-example-of-how-to-use-getopts-in-bash)
```bash
#!/bin/bash

usage() { echo "Usage: $0 [-s <45|90>] [-p <string>]" 1>&2; exit 1; }

while getopts ":s:p:" o; do
  case "${o}" in
    s)
      s=${OPTARG}
      ((s == 45 || s == 90)) || usage
      ;;
    p)
      p=${OPTARG}
      ;;
    *)
      usage
      ;;
esac
done
shift $((OPTIND-1))

if [ -z "${s}" ] || [ -z "${p}" ]; then
  usage
fi

echo "s = ${s}"
echo "p = ${p}"
```
<br> Example runs:

```text
$ ./myscript.sh
Usage: ./myscript.sh [-s <45|90>] [-p <string>]

$ ./myscript.sh -h
Usage: ./myscript.sh [-s <45|90>] [-p <string>]

$ ./myscript.sh -s "" -p ""
Usage: ./myscript.sh [-s <45|90>] [-p <string>]

$ ./myscript.sh -s 10 -p foo
Usage: ./myscript.sh [-s <45|90>] [-p <string>]

$ ./myscript.sh -s 45 -p foo
s = 45
p = foo

$ ./myscript.sh -s 90 -p bar
s = 90
p = bar
```

## sed
### 正規表示式
+ . 1點代表一個char

```text
.T.: 代表3個字元, 中間為T
```
+ \^ 在列首

```text
^: 代表位置在列開頭; ^cwm: 代表cwm在列開頭.
```
+ \$ 在尾部

```text
123$
```
+ \\{...\\} 指定符合的個數

```text
\{3,5}\: 表示前面的字元有3~5個. [a-z]\{3,5\}: 以小寫字母組成長度3~5.
```
+ \\(...\\) 把比對符合的字串暫時保存起來.

```text
H\(...\)Y 表示要保存H和Y之間的3個字元. \1 代表第1個保存的字串, \2代表第2個
```
+ Pattern

```text
sed '樣式命令' 檔案
sed -e '樣式命令1' -e '樣式命令2' -e '樣式命令3' -e '樣式命令4' 檔案
sed -f 樣式命令檔 檔案
```

### Example

+ insert

```text
sed -n 's/\(La\)/\1Oo/p' file

# Used to $var
sed "s/\(^\)/$var\/\1/g"
```

+ Modication String

將字串〝is〞改為〝IS〞(單字前沒加空隔)

```bash
echo 'This is a book' | sed 's/is/IS/g'
# +g: Replace all particular string.a to string.b
# -g: Replace first particular string.a to string.b

echo 'This is a book' | sed 's/ is/ IS/g'
echo 'This is a book' | sed 's/\<is\>/IS/g'
sed 's/\<is\>/IS/g' fileA
sed 's/\<is\>/IS/g' fileA fileB fileC
sed -i 's/\<is\>/IS/g' fileA fileB fileC # -i changed origin file
```
將檔案"my_file.txt"中第 4-5 行中的字串"Google"改"Yahoo"並存檔為"new.txt"

```bash
cat my_file.txt | sed '4,5 s/Google/Yahoo/g' > new.txt
sed '4,5 s/Google/Yahoo/g' < my_file.txt > new.txt
```

如要搜尋和取代的樣板不只一個,可用選項"-e"或管線再處理。
```bash
echo 'this is a apple' | sed 's/a/an/' | sed 's/apple/APPLE/'
echo 'this is a apple' | sed -e 's/a/an/' -e 's/apple/APPLE/'
```

+ window path to linux path

```bash
echo '\project\w2\worktree' | sed 's/\\/\//g'
```
+ linux path to windows path

```bash
echo '/abc/wxy' | sed 's/\//\\/g'
```

+ svn export from directories

```bash
# ! bin/bash
svn list --username user --password xxxx --non-interactive http://172.16.3.240/svn/common/Algorithm/CommonAlgo/XP_NANO/ > list_algo.log

echo "# !/bin/bash" > svn_export.sh
chmod u+x svn_export.sh
cat list_algo.log | sed 's/\(^cwm\)/svn export --username smith.hu --password 123456 --non-interactive http:\/\/172.16.3.240\/svn\/common\/Algorithm\/CommonAlgo\/XP_NANO\/\1/g' >> svn_export.sh

source svn_export.sh
```

+ replace particular string in more files

```bash
files=$(grep -rw --include=*.{c,h} 'SET_ARRTIBUTE_REALTIME' ./ | awk '{print $1}' | sed 's/.$//')
sed -i 's/\<SET_ARRTIBUTE_REALTIME\>/SET_ATTRIBUTE_REALTIME/g' $files
```

[ref.1](http://wanggen.myweb.hinet.net/ach3/ach3.html?MywebPageId=2018251532505598264#option)

## echo
```bash
echo -n "Hello World" # -n, 不需要自動換行
echo -e "I am the king\nof the world" # -e, 讓字串中的特殊字元有作用, \n, 代表換行
```

## xxd
Create C header file from binary image files
<pre>#Create C header file from binary image files <code>
# !/bin/sh
DRAM_FILE_NAME=os.checked.dram.0x40000400
IRAM_FILE_NAME=os.checked.iram.0x40080000

DRAM_FILE_SIZE=$(stat -c%s "$DRAM_FILE_NAME")
IRAM_FILE_SIZE=$(stat -c%s "$IRAM_FILE_NAME")

echo "Size of $DRAM_FILE_NAME = $DRAM_FILE_SIZE bytes."
echo "Size of $IRAM_FILE_NAME = $IRAM_FILE_SIZE bytes."

dram_chunk=$(($DRAM_FILE_SIZE / 256))
dram_unchunk=$(($DRAM_FILE_SIZE % 256))
iram_chunk=$(($IRAM_FILE_SIZE / 256))
iram_unchunk=$(($IRAM_FILE_SIZE % 256))

if [ $dram_unchunk -ne 0 ]; then
  dram_chunk=$(($dram_chunk + 1))
  size=$(($dram_chunk * 256))
  dram_pad_size=$(($size-$DRAM_FILE_SIZE))
  dd if=/dev/zero bs=1 count=$dram_pad_size >> $DRAM_FILE_NAME
  echo "Padding of $DRAM_FILE_NAME = $(stat -c%s "$DRAM_FILE_NAME") bytes."
fi

if [ $iram_unchunk -ne 0 ]; then
  iram_chunk=$(($iram_chunk + 1))
  size=$(($iram_chunk * 256))
  iram_pad_size=$(($size-$IRAM_FILE_SIZE))
  dd if=/dev/zero bs=1 count=$iram_pad_size >> $IRAM_FILE_NAME
  echo "Padding of $IRAM_FILE_NAME = $(stat -c%s "$IRAM_FILE_NAME") bytes."
fi

export in_dram_img=os.checked.dram.0x40000400
export in_iram_img=os.checked.iram.0x40080000
export out_dram_h=cmh1000_dram_img.h
export out_iram_h=cmh1000_iram_img.h

rm -f  $out_dram_h $out_iram_h
echo -e "/*The file is built on $(date '+%m-%d-%H-%M-%Y')*/ \n" > $out_dram_h
xxd -i $in_dram_img | sed 's/unsigned/const static unsigned/g' >> $out_dram_h

echo -e "/*The file is built on $(date '+%m-%d-%H-%M-%Y')*/ \n" > $out_iram_h
xxd -i $in_iram_img | sed 's/unsigned/const static unsigned/g' >> $out_iram_h

echo "generate CMH1000 firmware array header files $out_dram_h $out_iram_h"
</code></pre>

## find
+ Find all file in particular path or exclude particular path

```bash
find . -path "*/04_pccm0117*" -type f
find . -type f ! -path "*/04_pccm0117*"
find . -type f -path "*/04_pccm0117*" -or -path "*/linaro/*"
```

+ Copy folder structure \(sans files\) from one location to another

```bash
find . -type d > dirs.txt #to create the list of directories, then
xargs mkdir -p < dirs.txt #to create the directories on the destination.
```
+ Copy particular files

```bash
  find $SRC_DIR -type f \( -name at_command_cmh1000.c \) |\
  xargs -I {} cp -rf --parents {} $DEST_DIR
  find $SRC_DIR -type f \( -name sensor_manager.c -or -name sensor_manager.h \) |\
  xargs -I {} cp -rf --parents {} $DEST_DIR
  cp -f --parents $SRC_DIR/project/mt2523_hdk/apps/phicomm_w2/src/sys_init.c $DEST_DIR
```
+ Import \*.c; \*.h from particular path to vim

```bash
# !/bin/bash
default_path=*/07_w906_zwcm0118/*

if [ -z $1 ]; then
  filelist=$(find . -path "$default_path" -type f \( -name "*.c" -or -name "*.h" \) | xargs)
  vim $filelist
else
  $default_path=$1
  filelist=$(find . -path "$default_path" -type f \( -name "*.c" -or -name "*.h" \) | xargs)
  vim $filelist
fi
```

## grep
### Usually, I search with
```bash
grep -rn --include=*.c 'pattern' ./
grep -rl --include=*.{c,h} 'SENS*' ./
grep -Ern --include=*.{c,h} 'pattern1|pattern2' ./ # Multi-pattern match
```
**[-R, -r, --recursive]**  <br>
**[-n, --line-number]**   <br>
**[-L, --files-without-match]**   <br>
**[-l, --files-with-matches]**    <br>
**[-w, --word-regexp]** - whole word has been match   <br>
**[-c, --count]**   <br>
**[-v, --invert-match]**    <br>
**[--exclude-dir=DIR]**   <br>

## awk
```bash
awk '{print $1}' filename.txt
```

### ouput more items
```bash
awk '{print $1,$2}' filename.txt
```
### if pattern is matched, output $1 and $2
```bash
awk '/<pattern>/{print $1,$2}' filename
```

## dd
### To crate a 0x00 data file
```bash
dd if=/dev/zero bs=1 of=/tmp/file bs=2M count=2000
```
  **bs:** block size, 1次讀取與寫入BYTES位元組的資料，此選項
  會覆蓋 **ibs** 與 **obs** 的設定.
  count=N:只處理N個輸入區塊,每個區塊的大小為 ibs。

### Padding zero bytes into a end of file
```bash
dd if=/dev/zero bs count=2148 >> file
```
### Create a 0xff file
```bash
dd if=/dev/zero bs=1k count=100 | \
tr "\000" "\377" > paddedFile.bin
```
  **\377** meaning 0xFF of octal.

### Padding a few 0x00 dummy bytes in the particular file
```bash
#! /bin/sh
DRAM_FILE_NAME=os.checked.dram.0x40000400
IRAM_FILE_NAME=os.checked.iram.0x40080000

DRAM_FILE_SIZE=$(stat -c%s "$DRAM_FILE_NAME")
IRAM_FILE_SIZE=$(stat -c%s "$IRAM_FILE_NAME")

dram_chunk=$(($DRAM_FILE_SIZE / 256))
dram_unchunk=$(($DRAM_FILE_SIZE % 256))
iram_chunk=$(($IRAM_FILE_SIZE / 256))
iram_unchunk=$(($IRAM_FILE_SIZE % 256))

if [ $dram_unchunk -ne 0 ]; then
  dram_chunk=$(($dram_chunk + 1))
  size=$(($dram_chunk * 256))
  dram_pad_size=$(($size-$DRAM_FILE_SIZE))
  dd if=/dev/zero bs=1 count=$dram_pad_size >> $DRAM_FILE_NAME
  echo "Pad $dram_pad_size ZERO bytes to $DRAM_FILE_NAME"
fi

if [ $iram_unchunk -ne 0 ]; then
  iram_chunk=$(($iram_chunk + 1))
  size=$(($iram_chunk * 256))
  iram_pad_size=$(($size-$IRAM_FILE_SIZE))
  dd if=/dev/zero bs=1 count=$iram_pad_size >> $IRAM_FILE_NAME
  echo "Pad $iram_pad_size ZERO bytes to $IRAM_FILE_NAME"
fi
```
## mount
### Mount a NAS directory
```bash
sudo mount -t cifs -o username=smith.hu,password=123456 //172.16.3.220/cwm_rd_nasvr/Document_Center/AE/Personal/Smith/ ./mnt/ae/
```

## ZIP/ UNZIP
### unzip
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
To test all zipfiles in **the current directory**, printing only the summaries


To do a singly quiet listing
```bash
unzip -l file.zip #To do a singly quiet listing
unzip -ql file.zip #To do a doubly quiet listing
```

### zip
Command format. The basic command format is:
zip options archive inpath inpath ...

#### archive all the source files in the current directory and its subdirectories
```bash
find ./out/mt2523_watch/watch_ref_design -maxdepth 1 -type f -print | \
zip -j source -@
```
```bash
find ./chre/firmware -type f -name "os.checked.*" -print | \
zip -j w2_cmh1000_fw_v15_1804Bxxx -@ #-j: junk-path
```

#### Achive 2 image files in zip file
```bash
GIT_TAG=$1

achive_fw_image()
{
  GIT_TAG_NUMBER=$(git tag -l --sort=-taggerdate | grep $GIT_TAG | head -1)
  if [ -z "$GIT_TAG_NUMBER" ]; then
    echo "GIT TAG: $1 is not existing"
  else
    rm -f sensorhub_fw_$GIT_TAG_NUMBER.zip
    echo -e "Create sensorhub_fw_$GIT_TAG_NUMBER.zip\n"
    find ./chre/firmware -type f -name "os.checked.*" -print | zip -qj sensorhub_fw_$GIT_TAG_NUMBER.zip -@
  fi
}

if [ -z "$GIT_TAG" ]; then
  echo "ERROR: \$1 is empty, you have to fill GIT tag keyword is similar \"04B\", \"08D\"...etc"
else
  achive_fw_image
fi
```

```bash
VER_NUM=$(echo "v15.$(cat chre/firmware/misc/variant/$1/Makefile | grep VARIANT | sed 's/FLAGS += -DVARIANT_VER=0x//')")
VARIANT_MK_PATH="chre/firmware/misc/variant/$1/Makefile"

achive_fw_image()
{
  rm -v sensorhub_fw_"${VER_NUM}".zip
  echo -e "Create sensorhub_fw_"${VER_NUM}".zip\n"
  find ./chre/firmware -type f -name "os.checked.*" -print | zip -qj sensorhub_fw_"${VER_NUM}".zip -@
}

if [ -f $VARIANT_MK_PATH ]; then
  echo "Project name is: $1"
  achive_fw_image
else
  echo "Error! Yours project name is empty: $1"
  echo "You should fill that it like as \$ source achive_cmh1000fw.sh 07_w906_zwcm0118"
  echo "Project name is as below:"
  find . -path "*/misc/variant/*" -type d -print | sed 's/.\/chre\/firmware\/misc\/variant\///'
fi
```

## GNU/Linux most wanted

+ executed multiple instruction

```bash
$ ./configure; make; make install
```

+ File and Partition Sizes

Show the total size on disk of files or
directories (disk usage):

```bash
$ du -sh dir1 dir2 file1 file2
```

Number of bytes, words and lines in file:

```bash
$ wc file
```

Show the size, total space and free space of the
current partition:

```bash
df -h .
```

Display these info for all partitions:

```bash
df -h
```

## Use Case

+ change enum to string and enum number

```text
typedef enum {
    SET_INVAILD = 0x00010000,
    SET_AOUT_LOGON,
    SET_AOUT_LOGOFF,
    SET_RAWSENS_LOGON,
    SET_RAWSENS_LOGOFF,
    SET_DSET_LOGON,
    SET_DSET_LOGOFF,
    SET_ONESECTICK,

awk '/SET/{print $1, $1}' attribute_structure.h | sed -n '/^SET/p' > t1.log
cat t1.log | sed -n 's/\(^\)/{"/p' | sed -n 's/\(,\)/",/p' | sed -n 's/\(,$\)/},/p'

Output:

{"SET_AOUT_LOGON", SET_AOUT_LOGON},
{"SET_AOUT_LOGOFF", SET_AOUT_LOGOFF},
{"SET_RAWSENS_LOGON", SET_RAWSENS_LOGON},
{"SET_RAWSENS_LOGOFF", SET_RAWSENS_LOGOFF},
{"SET_DSET_LOGON", SET_DSET_LOGON},
{"SET_DSET_LOGOFF", SET_DSET_LOGOFF},
{"SET_ONESECTICK", SET_ONESECTICK},
{"SET_ATTRIBUTE_OP_START=0x00020000", SET_ATTRIBUTE_OP_START=0x00020000},
{"SET_ATTRIBUTE_ACTIVATED", SET_ATTRIBUTE_ACTIVATED},
{"SET_ATTRIBUTE_DEACTIVATED", SET_ATTRIBUTE_DEACTIVATED},

```

####

####




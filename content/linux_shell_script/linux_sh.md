##  awk
```bash
awk '{print $1}' filename.txt
```
+ ouput more items
```bash
awk '{print $1,$2}' filename.txt
```
+ if pattern is matched, output $1 and $2
```bash
awk '/<pattern>/{print $1,$2}' filename
```

## dd, shell script
To crate a 0x00 data file
```bash
dd if=/dev/zero bs=1 of=/tmp/file bs=2M count=2000
```
  **bs:** block size, 1次讀取與寫入BYTES位元組的資料，此選項
  會覆蓋 **ibs** 與 **obs** 的設定.
  count=N:只處理N個輸入區塊,每個區塊的大小為 ibs。

**ex:** Padding zero bytes into a end of file
```bash
dd if=/dev/zero bs count=2148 >> file
```
**ex**: create a 0xff file:
```bash
dd if=/dev/zero bs=1k count=100 | \
tr "\000" "\377" > paddedFile.bin
```
  "\377" meaning 0xFF of octal.

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

#### zip
Command format. The basic command format is:
zip options archive inpath inpath ...

# shell script - archive all the source files in the current directory and its subdirectories:
```bash
find ./out/mt2523_watch/watch_ref_design -maxdepth 1 -type f -print | \
zip -j source -@
```
```bash
find ./chre/firmware -type f -name "os.checked.*" -print | \
zip -j w2_cmh1000_fw_v15_1804Bxxx -@ #-j: junk-path
```

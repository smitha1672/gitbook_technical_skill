#
## Virtual Memory

<img src="https://bayanbox.ir/view/581244719208138556/virtual-memory.jpg"
width="100%"
height="100%"
alt="virtual memory"
align=center />

## Archive File (\*.a)
+ Create an archive with the ar command (archive command (ar))

```text
ar -rcs libhfsecurity.a encrypt.o checksum.o
```
<br>
<img src="archive-2.png"
width="80%"
height="80%"
alt="ar libhfsecurity.a"
align=center />

+ Use an Archive File

```text
$ gcc test_code.c -lhfsecurity -o test_code
-l: If you’re using several archivesyou can set several -l options.

$ gcc test_code.c -L/my_lib -lhfsecurity -o test_code
-L: To say which directories to search
```

+ Can I extract a single object file from an archive?

```text
$ ar -x libhfsecurity.a encrypt.o
```

+ If I’ve created a library archive, can I see what’s inside it?

```text
$ ar -t <filename>
```

## nm Linux Command

+ Look inside an archive (\*.a) <br>
libl.a contains libmain.o and libyywrap.o

```text
$ nm liba.a #look inside an archive
```
<br>
<img src="archive-1.png"
width="80%"
height="80%"
alt="look inside with libl.a"
align=center />


+ Display Object Files that Refer to a Symbol <br>
[10 Practical Linux nm Command Examples](https://www.thegeekstuff.com/2012/03/linux-nm-command/) <br>
[Linux nm Command Tutorial for Beginners (10 Examples)](https://www.howtoforge.com/linux-nm-command/) <br>

The following command displays all the object files that refer to the symbol ‘func’ in my current directory

```text
$ nm  -A ./*.o | grep func

./hello2.o:0000000000000000 T func_1
./hello3.o:0000000000000000 T func_2
./hello4.o:0000000000000000 T func_3
./main.o:                   U func
./reloc.o:                  U func
./reloc.o:0000000000000000  T func1
./test1.o:0000000000000000  T func
./test.o:                   U func
```

## GCC(GNU Compiler Collection)
<!---
<br> gcc -c/-S/-E/-o/-l/-L/-g
-->
<br> [reference link.1](https://wizardforcel.gitbooks.io/100-gcc-tips/content/syntax-only.html)
<br> syntax checking

```bash
gcc -fsyntax-only foo.c
```

```text
# [-c] and [-o] - Create a executable file
gcc -c test1.c test2.c test3.c -o test
=> 等效於
gcc -c test1.c test2.c test3.c
gcc test1.o test2.o test3.o -o test

:-c \*.c  # create \*.c to objective code
:-o \*.o -# Link all objective code to a executable file

# [-c] Create objective files
gcc -c test1.c test2.c test3.c
Noted: if -o exincludes, compiler cannot find out linking error.

# [-S] Compile c file to ASM
gcc -S test.c

# [-E] 將原始檔案(*.c)作進行預先處理而不是進行compile
可以用來展開marco, file include issue
gcc -E main.c -o maine.c

# [-l] include header file with particular path

# [-L] 指定 library 路徑

# [-g] it is used to gdb
會產生符號表, 讓gdb 工具可以除錯
```

## [valgrid](http://www.valgrind.org/docs/manual/quick-start.html#quick-start.prepare)

+ Installation

```bash
$ sudo apt install valgrind
```

+ Preparing your program

Compile your program with `-g` to include debugging information so that Memcheck's error messages
include exact line numbers. Using `-O0 is also a good idea`, if you can tolerate the slowdown. With
-O1 line numbers in error messages can be inaccurate, although generally speaking running Memcheck
on code compiled at -O1 works fairly well, and the speed improvement compared to running -O0 is
quite significant. Use of -O2 and above is not recommended as Memcheck occasionally reports
uninitialised-value errors which don't really exist.

+ Running your program under Memcheck

```bash
valgrind --leak-check=yes myprog arg1 arg2 #or
valgrind --leak-check=full myprog arg1 arg2 #or
cat ./src/slog1.csv | valgrind --leak-check=yes ./build/cwmAlgo
```
output:

```text
==4856==
==4856== HEAP SUMMARY:
==4856==     in use at exit: 22,716 bytes in 241 blocks
==4856==   total heap usage: 58,485 allocs, 58,244 frees, 2,317,427 bytes allocated
==4856==
==4856== LEAK SUMMARY:
==4856==    definitely lost: 0 bytes in 0 blocks
==4856==    indirectly lost: 0 bytes in 0 blocks
==4856==      possibly lost: 0 bytes in 0 blocks
==4856==    still reachable: 22,716 bytes in 241 blocks
==4856==         suppressed: 0 bytes in 0 blocks
==4856== Reachable blocks (those to which a pointer was found) are not shown.
==4856== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==4856==
==4856== For counts of detected and suppressed errors, rerun with: -v
==4856== Use --track-origins=yes to see where uninitialised values come from
==4856== ERROR SUMMARY: 6265 errors from 9 contexts (suppressed: 0 from 0)
```

## [GDB](http://puremonkey2010.blogspot.com/2010/07/gdb-gdb.html)

+ set break on the C file

```text
break xxx.c:line number
```

## Makefile
<br> Only output error message on screen

```text
make 2>&1 | tee filetokeepitin.txt

make 1 > build.log
1 meaning standard output
2 meaning standard error output
```

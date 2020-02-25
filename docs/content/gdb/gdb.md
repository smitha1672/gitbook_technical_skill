# GDB

```text
run <arg1 arg2...>
break <line-number>
    # break 6
break <function-name>
    # break func
break <line number> if <conditional expression>
    # break 12 if i==9
break <filename:line-number>
    # break temp.c:10
break <filename:function-name>
    # break temp.c:main
info break
delete breakpoint <point-number>
    # delete breakpoint 1
enable breakpoint <point-number>
    # enable breakpoint 1
disable breakpoint <point-number>
    # disable breakpoint 1
watch <condition>
    # watch i==3
file test4
    # test4 is a executable file

```

## HANDLE SIGNAL

```text
(gdb) handle SIGABRT noprint
(gdb) handle SIG36 noprint
```

## BREAK POINT

```text
(gdb) break <filename:line-number>
(gdb) break <filename:function name>
```

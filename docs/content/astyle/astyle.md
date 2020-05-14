# ASTYLE

[Quick Start](http://astyle.sourceforge.net/astyle.html#_Quick_Start)

## INSTALL

```text
$ mkdir home/smith/tmp/
$ cd home/smith/tmp/
$ wget https://sourceforge.net/projects/astyle/files/astyle/astyle%203.1/astyle_3.1_linux.tar.gz
$ tar zxvf astyle_3.1_linux.tar.gz
$ cd astyle/build/gcc
$ make (output: /home/smith/tmp/astyle/build/gcc/bin/astyle)
```

## LINK ASTYLE

```text
$ mkdir -p /home/smith/usr/bin
$ cp -v /home/smith/tmp/astyle/build/gcc/bin/astyle /home/smith/usr/bin/

add PATH=/home/smith/usr/bin:$PATH in /home/smith/.bashrc
$ logout
$ login
$ echo $PATH
# output
/home/smith/usr/bin:/home/smith/usr/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games

$ astyle -V
# output Artistic Style Version 3.1
```

## HOW TO USE

```text
astyle --style=linux -pHk3 *.c/*.h
```

## STYLE

### ATTACH RETURN TYPE

```text
--attach-return-type      / -xf
--attach-return-type-decl / -xh
```

```text
void
Foo(bool isFoo);
becomes:

void Foo(bool isFoo);
```

### BREAK RETURN TYPE

```text
--break-return-type      / -xB
--break-return-type-decl / -xD
```

```text
void Foo(bool isFoo);
becomes:

void
Foo(bool isFoo);
```


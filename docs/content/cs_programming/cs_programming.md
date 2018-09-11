## Virtual Memory

<img src="https://bayanbox.ir/view/581244719208138556/virtual-memory.jpg"
width="100%"
height="100%"
alt="virtual memory"
align=center />


## Basic C
+ while (some condition)

```c
while (...) {
  break;  /*leave loop*/
}

while (...) {
  continue;   /*go to while*/
}
```
+ for (initial variable; judge expression; execute code)

```c
for (int counter = 1; counter < 11; counter ++)
```

+ if

```c
if (intput > 0)
  classify = "postive"
else
  classify = "negative"

/*equal to*/
classify = (input)? "postive": "negative";
```

+ Print memory address

```c
printf("x %p\n", &x); /*%p is meaning: showing x address as HEX format output*/
```

+ const int\*, const int \* const, and int const \*

<br>
<img src="https://i.stack.imgur.com/Zt0G2.png"
width="70%"
height="70%"
alt="const pointer to const int"
align=center />

<br>
<img src="https://i.stack.imgur.com/kXH8P.png"
width="70%"
height="70%"
alt="pointer to int const"
align=center />

<br>
<img src="https://i.stack.imgur.com/UeqZO.png"
width="70%"
height="70%"
alt="pointer to const int"
align=center />

<br>
<img src="https://i.stack.imgur.com/f5ftV.png"
width="70%"
height="70%"
alt="const pointer to int"
align=center />

+ **(\*t).age != \*t.age**

```text
(*t).age is not equal to *t.age
(*t).age = t->age
*t.age = *(t.age) # it refer as memory address
ptr->field = (*ptr).field
```

+ Get struct member size

```c
#define member_size(type, member) sizeof(((type *)0)->member)

typedef struct
{
    float calc;
    char text[255];
    int used;
} Parent;

typedef struct
{
    char flag;
    char text[member_size(Parent, text)];
    int used;
} Child;

printf("%zu", member_size(Parent,text));
```

+ Get array size

```c
#define ARRAY_SIZE(a)   (sizeof((a)) / sizeof((a)[0]))
```

+ union and sturct
<br> **union**: 提供memory足以存放最大SIZE的空間
<br> union initialize

```c
typedef union {
  shot count;   //2 bytes
  float weight; //4 bytes
  float volume; //4 bytes
} quantity; //this is 4 bytes size

/*initialize a union*/
quantity q = {4}; //set 4 to count

/*set weight*/
quantity q = {.weight=1.5};
```
<br> structure initialize

```c
struct bick_t {
  const char* color;
  int gears;
  int height;
} bick = {.height = 17, .gears = 21};
```

+ array pointer

```c
void print_pointer_array(int *p[])
{
  for(int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("p[%d][%d] = %d\n", i, j,  *(p[i] + j));
    }
  }
}

void main(void)
{
  int acc[3] = {1, 2, 3};
  int gyro[3] = {4, 5, 6};
  int mag[3] = {7, 8, 9};
  int *p[3]= {NULL, };
  p[0] = acc;
  p[1] = gyro;
  p[2] = mag;
  print_pointer_array(p);
}
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
+ nm
+ ar -t/-x/rcs

## valgrid
## Makefile
<br> Only output error message on screen

```text
make 1 > build.log
1 meaning standard output
2 meaning standard error output
```
## nm

## Astyle

```text
apt-get install astyle
```

+ Normally usage

```text
astyle --style=linux -pHk3 *.c/*.h
```

[Quick Start](http://astyle.sourceforge.net/astyle.html#_Quick_Start)




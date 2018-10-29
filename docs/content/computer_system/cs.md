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

## C Technique

+ [Structure and Pointer](https://www.programiz.com/c-programming/c-structures-pointers)

Referencing pointer to another address to access the memory

```c
#include <stdio.h>
typedef struct person
{
    int age;
    float weight;
};

int main()
{
    struct person *personPtr, person1;
    personPtr = &person1; // Referencing pointer to memory address of person1

    printf("Enter integer: ");
    scanf("%d",&(*personPtr).age);

    printf("Enter number: ");
    scanf("%f",&(*personPtr).weight);

    printf("Displaying: ");
    printf("%d%f",(*personPtr).age,(*personPtr).weight);

    return 0;
}
```

Using -> operator to access structure pointer member

```text
(*personPtr).age is same as personPtr->age
(*personPtr).weight is same as personPtr->weight
```

Accessing structure member through pointer using dynamic memory allocation

```c
#include <stdio.h>
#include <stdlib.h>
struct person {
int age;
    float weight;
    char name[30];
};

int main()
{
    struct person *ptr;
    int i, num;

    printf("Enter number of persons: ");
    scanf("%d", &num);

    ptr = (struct person*) malloc(num * sizeof(struct person));
    // Above statement allocates the memory for n structures with pointer
    // personPtr pointing to base address */

    for(i = 0; i < num; ++i)
    {
        printf("Enter name, age and weight of the person
                respectively:\n");
        scanf("%s%d%f", &(ptr+i)->name, &(ptr+i)->age,
                &(ptr+i)->weight);
    }

    printf("Displaying Infromation:\n");
    for(i = 0; i < num; ++i)
    printf("%s\t%d\t%.2f\n",
            (ptr+i)->name, (ptr+i)->age,
            (ptr+i)->weight);

    return 0;
}
```

Output

```text
Enter number of persons: 2
Enter name, age and weight of the person respectively:
Adam
2
3.2
Enter name, age and weight of the person respectively:
Eve
6
2.3
Displaying Information:
Adam    2   3.20
Eve 6   2.30
```

volatile

```text
http://mropengate.blogspot.com/2017/08/cc-c.html
https://rmbconsulting.us/publications/a-c-test-the-0x10-best-questions-for-would-be-embedded-programmers/

由於嵌入式系統常處理 I/O、中斷、即時操作系統 (RTOS) 相關的問題，因此在嵌入式系統開發中 volatile
尤為重要。被 volatile 修飾的變數代表它可能會被不預期的更新，因此告知編譯器不對它涉及的地方做最佳化，
並在每次操作它的時候都讀取該變數實體位址上最新的值，而不是讀取暫存器的值。

volatile 常見的應用：
修飾中斷處理程式中 (ISR) 中可能被修改的全域變數。
修飾多執行緒 (multi-threaded) 的全域變數。
設備的硬體暫存器 (如狀態暫存器)
```

+ pointer

```text
int a; // 一個整型數
int *a; // 一個指向整數的指標
int **a; // 一個指向指標的指標，它指向的指標是指向一個整型數
int a[10]; // 一個有10個整數型的陣列
int *a[10]; // 一個有10個指標的陣列，該指標是指向一個整數型的
int (*a)[10]; // 一個指向有10個整數型陣列的指標
int (*a)(int); // 一個指向函數的指標，該函數有一個整數型參數並返回一個整數
int (*a[10])(int); // 一個有10個指標的陣列，該指標指向一個函數，該函數有一個整數型參數並返回一個整數
```

+ function pointer

```c
void (*fptr)(type_a, type_b) = &func;
```

+ Question

```c
void foo(void) {
    unsigned int a = 6;
    int b = -20;
    (a+b > 6) ? puts("> 6") : puts("<= 6");
}
```
```text
unsigned int的答案是輸出是 "> 6".
當表達式中存在有符號類型和無符號類型時所有的操作數都自動轉換為無符號類型(unsigned)。因此-20變成了一個非常大的正整數，所以該表達式計算出的結果大於6.
這一點對於應當頻繁用到無符號數據類型的嵌入式系統來說是非常重要的。如果你答錯了這個問題，你也就到了得不到這份工作的邊緣。
```

+ interruption fucntion

```c
__interrupt double compute_area(double radius) {
    double area = PI * radius * radius; 
    printf("\nArea = %f"， area);  return area;
}
```
```text
1. ISR 不能返回一個值。如果你不懂這個，那麼你不會被雇用的.
2. ISR 不能傳遞參數。如果你沒有看到這一點，你被雇用的機會等同第一項.
3. 在許多的處理器/編譯器中，浮點一般都是不可重入的。有些處理器/編譯器需要讓多餘的暫存器入棧(PUSH入堆疊)，有些處理器/編譯器就是不允許在ISR中做浮點運算。此外，ISR應該是短而有效率的，在ISR中做浮點運算是不明智的.
4. printf()經常有重入和性能上的問題。
如果你丟掉了第三和第四點，我不會太為難你的。但如果你能得到後兩點，那麼你的被雇用前景越來越光明了。
```

+ Using inline

其作用是將fucntion展開, 把fucntion的程式碼copy到每一個call place,
這樣在call function的過程就可以直接execute function code, 而不發生
jump, 進入stack等一般性fucntion manipuation, 可以節省時間, 提昇程式
executable speed.

```c
inline int f(int a, int b) {
    return a+b;
}

int main(void) {
    int c;
    c = f(1,2); /*=> 展開inline 成為 c = 1+2*/
    return 1;
}
```

+ Using a Union to Represent a Value in Multiple Ways

```c
typedef union _conversion {
     float fNum;
      unsigned int uiNum;
} Conversion;
int isPositive1(float number) {
    Conversion conversion = { . fNum =number};
    return (conversion. uiNum & 0x80000000) == 0;
}

typedef union _conversion2 {
    float *fNum;
    unsigned int *uiNum;
} Conversion2;
int isPositive2(float number) {
    Conversion2 conversion;
    conversion.fNum =&number;
    return (*conversion.uiNum & 0x80000000) == 0;
}

int isPositive3(float number) {
    unsigned int *ptrValue = (unsigned int *)&number;
    return (*ptrValue & 0x80000000) == 0;
}
```

+ Strict Aliasing Keyword

```text
Strict aliasing is another form of aliasing. Strict aliasing does not allow a pointer of one
data type to alias a pointer of a different data type.

In the following code sequence, a pointer to an integer aliases a pointer to a float.
This violates the strict aliasing rule.
```
```c
float number = 3.25f;
unsigned int *ptrValue = (unsigned int *)&number;
unsigned int result = (*ptrValue & 0x80000000) == 0; /*a good way is for judgeting postive or nagtive*/
```
```text
If your compiler has an option to disable strict aliasing,
it can be turned off. The GCC compiler has the following compiler options:
-fno-strict-aliasing to turn it off
-fstrict-aliasing to turn it on
-Wstrict-aliasing to warn of strict aliasing-related problems
```

+ Determining the Endianness of a Machine

```c
int num = 0x12345678;
char* pc = (char*) &num;
for (int i = 0; i < 4; i++) {
    printf("%p: %02x \n" , pc, (unsigned char) *pc++);
}

Output:
100: 78
101: 56
102: 34
103: 12 /*little-endian*/
```

+ Accessing a Port

```c
/*
The volatile keyword qualifier indicates that the variable can
be changed outside of the program.

Using the volatile keyword will prevent the runtime system from using a register to
temporarily store the port value. Each port access requires the system to read or write
to the port instead of reading a possibly stale value stored in a register
*/

#define PORT 0xB0000000
unsigned int volatile * const port = (unsigned int *) PORT
*port = 0x0BF4; // write to the port
value = *port;  // read from the port
```

+ Accessing a Special Purpose Address

```c
#define VIDEO_BASE 0xB8000
int *video = (int *) VIDEO_BASE;
*video = 'A';
```

+ Setting a Start Address for the Array Used by Heap4

```c
/*Using GCC syntax*/
uint8_t ucHeap[configTOTAL_HEAP_SIZE] __attribute__ ((section(".my_heap"))); /*.my_heap should exist in linker file*/

/*Using IAR*/
uint8_t ucHeap[configTOTAL_HEAP_SIZE ] @ 0x20000000;
```

+ Bit Manipulation

```c
#define BIT_MASK(bitn) \
    ((1U << (bitn)) - 1)

#define BIT_SET(data, bitn) \
    data |= (1UL << bitn)

#define BIT_CLR(data, bitn) \
    data &= ~(1UL << bitn)

#define BIT_TOGGLE(data, bitn) \
    data ^= (1UL << bitn)

#define BIT_CHECKED(data, bitn) \
    (data >> bitn) & 1U

#define BIT_SET_NTH_BIT(data, bitn, binary) \
    data ^= (-binary ^ data) & (1UL << bitn)
```

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

## valgrid
## Makefile
<br> Only output error message on screen

```text
make 1 > build.log
1 meaning standard output
2 meaning standard error output
```

## Astyle

```text
apt-get install astyle
```

+ Normally usage

```text
astyle --style=linux -pHk3 *.c/*.h
```

+ astylerc

```text
# this line is a comment
--style=linux      # this is a line-end comment

# Insert space padding around operators.
--pad-oper

# Insert space padding between a header (e.g. 'if', 'for', 'while'...)
--pad-header

# Attach a pointer or reference operator (*, &, or ^) to either the variable type (left) or variable name (right), or place it between the type and name (middle).
--align-pointer=name

# This option will align references separate from pointers.
--align-reference=name

# Do not retain a backup of the original file
--suffix=none

# Indent 'switch' blocks so that the 'case X:'
--indent-switches

# Indent using # spaces per indent.
--indent=spaces=4

# Delete empty lines within a function or method.
--delete-empty-lines

#Set the minimal indent that is added when a header is built of multiple lines.
--min-conditional-indent=0

# Indent a maximal # spaces in a continuous statement,
--max-instatement-indent=40

# The option max-code-length will break a line if the code exceeds # characters.
--max-code-length=80
--break-after-logical
```

[Quick Start](http://astyle.sourceforge.net/astyle.html#_Quick_Start)




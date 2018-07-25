## Virtual Memory
![Alt text][id]
[id]: https://bayanbox.ir/view/581244719208138556/virtual-memory.jpg "It is form yousha.blog.ir"

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

+ **(\*t).age != \*t.age**
```text
(*t).age is not equal to *t.age
(*t).age = t->age
*t.age = *(t.age) # it refer as memory address
ptr->field = (*ptr).field
```

+ union and sturct
<br> **union**: 提供memory足以存放最大SIZE的空間

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


## GCC(GNU Compiler Collection)
+ Create a executable file

```bash
gcc -c *.c  # create \*.c to objective code
gcc *.o -o executable # Link all objective code to a executable file
```
+ gcc -L/ -I/ -E
+ nm
+ ar -t/-x/rcs


## valgrid
## Makefile
## nm

# PTHREAD
## [posix thread doc](https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html)

C commpiler: gcc -lpthread pthread1.c
or
C++ compiler: g++ -lpthread pthread1.c

# MESSAGE QUEUES

## EXAMPLE SERVER and CLIENT

[github](https://github.com/smitha1672/note/tree/master/cSkillTraning/linux_mqueue)
[link](https://stackoverflow.com/questions/3056307/how-do-i-use-mqueue-in-a-c-program-on-a-linux-based-system)

```text
#include <mqueue.h>

## [firmware path](https://blog.csdn.net/zifehng/article/details/60321966)

+ `request_firmware`

```text
// driver/base/firmware_class.c

static const char * const fw_path[] = {
    fw_path_para,
    "/system/etc/firmware",
    "/lib/firmware/updates/" UTS_RELEASE,
    "/lib/firmware/updates",
    "/lib/firmware/" UTS_RELEASE,
    "/lib/firmware",
};
```



#
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



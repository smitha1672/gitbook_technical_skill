## TERA TERM
[TERA TERM v4.99](https://tera-term.en.lo4d.com/download/mirror-ls1) can be used to deliver AT command on Window 10 OS. As illustrated figures, there are 3 instances with broadcast function
that is for enabling log message, showing CMH1000 firmware version and showing accelerometer sensor data.
More sensor hub AT commands are coded on `at_command_cmh1000.c`

When MT2523 was be powered on, "MTK USB Debug Port (COM19)" and "MTK USB Modem Port (COM18)" can be discovered by "Device Manager" on Windows 10.
COM19 is always be used on showing debug message; COM18 is be used to ATCI.

+ Setting TERA TERM instance
There are 2 termterm configuration files they need to place in same directory.
Copied below content and separately save to **MT2523_ACTI.bat** and **MT2523_ATCI_LOG_SAVING.ttl**.
On **MT2523_ACTI.bat** icon, double clicking right button on mouse, teraterm GUI will be showed on screen,
and it will automatically save all screen log in w2_lv1_xxx-xxx.log such as illustrated figure.

> MT2523_ACTI.bat

```text
SET PATH=C:\Program Files (x86)\teraterm;%PATH%
::MT2523 ATCI Port Enable
start TTERMPRO /C=18 /BAUD=115200 /M=%CD%\MT2523_ATCI_LOG_SAVING.ttl
```

> MT2523_ATCI_LOG_SAVING.ttl

```text
gettime timestr "%Y%m%d-%H%M%S"
getdir mdir
sprintf2 filename '%s\w2_lv1_%s.log' mdir timestr
logopen filename 0 0 0 0
```

+ [MACRO for Tera Term](https://ttssh2.osdn.jp/manual/en/macro/index.html)


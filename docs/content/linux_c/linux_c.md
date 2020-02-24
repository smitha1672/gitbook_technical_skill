# CRITIAL SECTIONS

+ SIGNAL

```text
#include <signal.h>

static sigset_t v_sigset_mask;
static sigset_t v_sigset_orimask;

static int _vcore_critial_section_entry(void)
{
    return (sigprocmask(SIG_BLOCK, &v_sigset_mask, &v_sigset_orimask));
}

static int _vcore_critial_section_exit(void)
{
    return (sigprocmask(SIG_SETMASK, &v_sigset_orimask, NULL));
}

void signal_setup(void)
{
    int iret = 0;

    /*kill -l is able to know how signal infor*/
    iret = sigaction(36, &act_new, NULL); /*36: SIGRTMIN+2*/
    sigemptyset(&v_sigset_mask);
    sigaddset(&v_sigset_mask, 36);
}

```

# PTHREAD
## [posix thread doc](https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html)

```text
C commpiler: gcc -lpthread pthread1.c
or
C++ compiler: g++ -lpthread pthread1.c
```

# IPC
## MESSAGE QUEUES

[posix.4-mqueue](https://users.pja.edu.pl/~jms/qnx/help/watcom/clibref/mq_overview.html) <br/>
[mqueue-github](https://github.com/smitha1672/note/tree/master/cSkillTraning/linux_mqueue) <br/>
[link](https://stackoverflow.com/questions/3056307/how-do-i-use-mqueue-in-a-c-program-on-a-linux-based-system)

## PIPE or FIFO

[mkfifo, GeeksforGeeks](https://www.geeksforgeeks.org/named-pipe-fifo-example-c-program/) <br/>
[mkfifo, github](https://github.com/smitha1672/note/tree/master/cSkillTraning/linux/mkfifo) <br/>

## MSG

[msg-ex1](https://www.itread01.com/content/1542371232.html)<br/>
[msg-ex2-geeksforgeeks](https://www.geeksforgeeks.org/ipc-using-message-queues/)

```
IPC_RMID
IPC_CREAT|0666
IPC_EXCL
```

```text
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// structure for message queue
struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message;

// ftok to generate unique key
key = ftok("progfile", 65);
...
mqid = msgget(MSGKEY,IPC_EXCL);
...
mqid = msgget(MSGKEY,IPC_CREAT|0666);
...
ret=msgrcv(mqid,&msg,sizeof(struct msgstru),1,0); /*1 has been to match mesg_type*/
...
msgsnd(msgid, &message, sizeof(message), 0);
...
msgctl(mqid,IPC_RMID,0); /*delete message fifo*/
```

# [SEMAPHORES]

For `Synchronizing Threads`

[Synchronizing Threads with POSIX Semaphores](http://www.csc.villanova.edu/~mdamian/threads/posixsem.html)



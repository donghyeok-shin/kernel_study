#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/sched.h>


int g=2;

int sub_func(void *arg)
{
    g++;
    printf("pdi(%d) : child g=%d \n", getpid(), g);
    sleep(2);
    return 0;
}

int main(void)
{
    int pid;
    int child_stack[4096];
    int i = 3;
    printf("pid(%d) : parent g=%d, i=%d \n", getpid(), g, i);
    clone(sub_func, (void *)(child_stack+4095), CLONE_VM | CLONE_THREAD | CLONE_SIGHAND, NULL);
    sleep(1);
    printf("pid(%d) : parent g=%d, i=%d \n", getpid(), g, i);
    return 0;
}
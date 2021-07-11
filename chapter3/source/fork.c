#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int g = 2;

int main(void)
{
    pid_t pid;
    int i = 3;

    printf("PID(%d): parent g=%d, i=%d\n", getpid(), g, i);

    if((pid=fork())<0) {
        perror("fork error");
        exit(1);
    } else if(pid == 0) {
        g++;
        i++;
    } else {
        wait();
    }

    printf("PID(%d): g=%d, i=%d\n", getpid(), g, i);


    return 0;
}
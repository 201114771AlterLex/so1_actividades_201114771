#include <stdio.h>
#include <unistd.h>

int main(){
    int ss=25;
    printf("Process ID: %d, Parent ID: %d\n", getpid(), getppid());
    sleep(ss);
    fork();

    printf("Process ID: %d, Parent ID: %d\n", getpid(), getppid());
    sleep(ss);
    fork();

    printf("Process ID: %d, Parent ID: %d\n", getpid(), getppid());
    sleep(ss);
    fork();

    printf("Process ID: %d, Parent ID: %d\n", getpid(), getppid());

    sleep(ss);
    return 0;
}
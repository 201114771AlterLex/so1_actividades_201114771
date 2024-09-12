#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h> 

void* thread_func(void* arg) {
    printf("Hilo creado. PID: %d, TID: %lu\n", getpid(), pthread_self());
    return NULL;
}

int main() {
    pid_t pid;
    printf("1 - Process ID: %d, Parent ID: %d\n", getpid(), getppid());

    pid=fork();
    printf("2 - Process ID: %d, Parent ID: %d\n", getpid(), getppid());
    if (pid == 0) {
        printf("3 - Process ID: %d, Parent ID: %d\n", getpid(), getppid());
        fork();
        printf("3.1 - Process ID: %d, Parent ID: %d\n", getpid(), getppid());
        pthread_t thread;
        if (pthread_create(&thread, NULL, thread_func, NULL) != 0) {
            perror("Error al crear el hilo");
            exit(1);
        }

        pthread_join(thread, NULL);
        printf("3.2 - Process ID: %d, Parent ID: %d\n", getpid(), getppid());
    } 
    printf("4 - Process ID: %d, Parent ID: %d\n", getpid(), getppid());
    fork();
    printf("5 - Process ID: %d, Parent ID: %d\n", getpid(), getppid());

    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        printf("Padre: Mi hijo tiene PID %d y mi PID %d\n", pid,getpid());
        sleep(60); 
        printf("Padre: Ahora recojo a mi hijo zombie...\n");
        wait(NULL); 
    } else if (pid == 0) {
        printf("Hijo: Temine. Mi PID es %d y mi padre es %d \n", getpid(),getppid());
        exit(0); 
    } else {
        perror("fork() fallo");
        exit(1);
    }

    return 0;
}
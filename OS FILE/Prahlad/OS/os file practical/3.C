#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    printf("\nName - Prahlad Singh Aswal\nSection - A\n");
    printf("Student id - 20011854\n\n");

    printf("\nZombie Process\n");
    // int pid = fork();
    // PARENT PROCESS
    if (pid > 0)
    {
        sleep(10);
        printf("\nParent Process\n");
        printf("PID of Parent process is: %d\n", getpid());
    }

    // CHILD PROCESS
    else
    {
        printf("\nChild Process\n");
        printf("PID of Child process is: %d\n", getpid());
        printf("PID of the parent process is: %d\n", getppid());
        exit(0);
    }
    return 0;
}
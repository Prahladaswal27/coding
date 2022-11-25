#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    printf("\nName - Prahlad Singh Aswal\nSection - A\n");
    printf("Student id - 20011854\n\n");

    printf("\nOrphan Process\n");
    // int pid = fork();

    // PARENT PROCESS
    if (pid > 0)
    {
        printf("\nParent Process\n");
        printf("PID of process is: %d\n", getpid());
        exit(0);
    }

    //CHILD PROCESS
    else
    {
        sleep(10);
        printf("\nChild Process\n");
        printf("PID of process is: %d\n", getpid());
        printf("PID of parent process is: %d\n",getppid());
    }
    return 0;
}
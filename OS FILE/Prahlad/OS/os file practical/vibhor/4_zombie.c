/* A process which has finished its execution but still has an entry in the process table to report to its parent process is known as a zombie process.
here we have made the will sleep for 24 sec, so it will complete its execution after 24 sec.
But, Child will finish its execution using exit() system call while its parent process has gone for sleep. */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("\nName-Vibhor Goswami\nSec-A\nStudent id=20011888\n");
    // Fork returns process id
    // in parent process
    int ProcessID = fork();

    // Parent process
    if (ProcessID > 0)
    {
        sleep(10);
        printf("\nParent Process\n");
        printf("PID: %d\n", getpid());
    }

    // Child process
    else
    {
        printf("\nChild process\n");
        printf("PID: %d\n", getpid());
        printf("Parent PID : %d\n", getppid());
        exit(0);
    }

    return 0;
}
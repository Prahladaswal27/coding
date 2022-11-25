// that process whose parent process has Completed its execution or has been terminated and do not exists in the process table are called orphan process.
// Generally a parent process waits for its child to terminate and report to it after execution but if he unable to do so it is called as Orphan process
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("\nName-Vibhor Goswami\nSec-A\nStudent id=20011888\n");
    int ProcessID = fork();

    if (ProcessID > 0)
    {
        printf("\nParent process\n");
        printf("PID: %d\n", getpid());
        exit(0);
    }

    // ProcessID = 0 in child process
    // ProcessID is negative if fork() fails
    else if (ProcessID == 0)
    {
        sleep(10);
        printf("\nChild process\n");
        printf("PID: %d\n", getpid());
        printf("Parent PID : %d\n", getppid());
    }

    return 0;
}

/*
    Write a C program to demonstrate Orphan Process.

    Orphan Process is a process in which the Parent process terminates before the child process. The child's process is put to sleep for a long time using the sleep function. This will put the child process to sleep and the parent process is terminated making the child process orphan.

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    printf("\nName - Vipul Chauhan\nSection - A\nStudent id - 20011016\n\n");
    int pid=fork();
    if(pid > 0)
    {
        printf("\nThis is Parent Process....\n");
        printf("PID: %d\n",getpid());
        exit(0);
    }
    else
    {
        sleep(10);
        printf("\nThis is Child Process....\n");
        printf("PID: %d\n",getpid());
        printf("Parent PID : %d\n",getppid());
    }
    return 0;
}*/
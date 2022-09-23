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
        printf("\nParent process\n");

    // ProcessID = 0 in child process
    // ProcessID is negative if fork() fails
    else if (ProcessID == 0)
    {
        sleep(10);
        printf("\nChild process\n");
    }

    return 0;
}
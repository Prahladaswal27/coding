A process which has finished its execution but still has an entry in the process table to report to its parent process is known as a zombie process.
here we have made the will sleep for 24 sec, so it will complete its execution after 24 sec. But, Child will finish its execution using exit() system call while its parent process has gone for sleep.
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    // Fork returns process id
    // in parent process
    int ProcessID = fork();
  
    // Parent process 
    if (ProcessID > 0)
        sleep(24);
  
    // Child process
    else        
        exit(0);
  
    return 0;
}
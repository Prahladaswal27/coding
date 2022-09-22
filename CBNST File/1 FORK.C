Fork -> Fork system call is a threading based function which 
creates a new process by duplicating the calling process.
using fork() function, we can create a same copy of the calling process

or fork() is used to create a child process of calling process.

#include<stdio.h>
#include<unistd.h>
int main()
{
fork();
int PId = getpid();
// pid means Process ID
printf("INDIAN MILITARY ACADEMY , PID is : %d\n", PId);
return 0;
}
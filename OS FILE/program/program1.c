#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("\nName - Prahlad Singh Aswal \nSection – A");
    printf("\nStudent id - 20011854\n\n");
    
    fork();
    printf("Hello World!\n");
    printf("Get PID: %d\n\n", getpid());
    
    return 0;
}

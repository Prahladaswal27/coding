#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("\nName - Prahlad Singh Aswal\nSection - A\n");
    printf("Student id - 20011854\n");

    // fork();
    printf("\nOperating System\n");
    printf("PID is: %d\n", getpid());

    return 0;
}

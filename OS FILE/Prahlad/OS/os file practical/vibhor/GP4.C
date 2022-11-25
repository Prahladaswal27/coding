#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("\n Name- Gajendra Babu \n Sec- A \n Student Id- 2018337 \n\n");
    int pid = fork();

    if (pid > 0)
    {
        sleep(5); // waits for 5 seconds
        printf("\nParent Process\n");
        printf("PID: %d\n", getpid());
    }

    else
    {
        printf("\nChild process\n");
        printf("PID: %d\n", getpid());
        printf("Parent PID : %d\n", getppid());
        exit(0);
    }

    return 0;
}

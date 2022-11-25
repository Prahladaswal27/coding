#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("\n Name- Gajendra Babu \n Sec- A \n Student Id- 2018337 \n\n");
    int P_id = fork();

    if (P_id > 0)
    {
        printf("\nParent Process\n");
        printf("PID: %d\n", getpid());
        exit(0);
    }

    // parent process terminates first in orphan process

    else if (P_id == 0)
    {
        sleep(5); // sleep for 5 seconds
        printf("\nChild process\n");
        printf("PID: %d\n", getpid());
        printf("Parent PID : %d\n", getppid());
    }

    return 0;
}

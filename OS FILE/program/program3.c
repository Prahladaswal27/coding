#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("\nName - Prahlad Singh Aswal \nSection – A");
    printf("\nStudent id - 20011854\n\n");
   
    int pid=fork();
    
    if (pid>0)
	{
 		printf("This is Parent Process\n\n");
	}

	else
 	{
   		sleep(10);
   		printf("This is Child Process\n\n");
 	}
 	return 0;
}

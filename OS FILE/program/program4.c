
// zombie process

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
  	printf("\nName - Prahlad Singh Aswal \nSection – A");
    printf("\nStudent id - 20011854\n\n");
    
  	int pid=fork();
  
  	if(pid>0)
  	{
   		sleep(10);
   		printf("This is Parent process\n\n");
  	}
  	
  	else
  	{
   		exit(0);
   		printf("This is Child Process\n\n");
  	}
  	return 0;
}

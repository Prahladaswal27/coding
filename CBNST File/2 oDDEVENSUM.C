We are using fork() function to create two processes, one is child and one is parent process. 

For child process fork() returns 0, using that we will calculate sum of all odd numbers in child process. 
fork() also returns value greater than 0 for parent process using which we will find sum 
for all even numbers.




// C++ program to demonstrate calculation in parent and
// child processes using fork()
#include <stdio.h>
#include <unistd.h>
using namespace std;

int main()
{
	int b[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sumO = 0, sumE = 0, n, i;
	n = fork();

	// Parent process
	if (n > 0) {
		for (i = 0; i < 10; i++) {
			if (b[i] % 2 == 0)
				sumE = sumE + b[i];
		}
		printf ("Parent process \n");
		printf ("Even sum is :- %d\n", sumE);
	}

	// Child process
	else {
		for (i = 0; i < 10; i++) {
			if (b[i] % 2 != 0)
				sumO = sumO + b[i];
		}
		printf ("Child process \n");
		printf ("Odd sum is :- %d\n", sumO);
	}
	return 0;
}

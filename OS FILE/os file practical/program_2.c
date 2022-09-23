#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("\nName - Prahlad Singh Aswal\nSection - A\n");
    printf("Student id - 20011854\n\n");

    int n;
    int e_sum = 0, o_sum = 0;

    printf("\nEnter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int pid = fork();
    int i = 0;

    if (pid == 0)
    {
        while (i < n)
        {
            if (arr[i] % 2 != 0)
                o_sum += arr[i];
            i++;
        }

        printf("\nSum of all odd numbers in array = %d\n", o_sum);
    }
    else
    {
        while (i < n)
        {
            if (arr[i] % 2 == 0)
                e_sum += arr[i];
            i++;
        }
        printf("\nSum of all even numbers in array= %d\n", e_sum);
    }
    return 0;
}

// #include<stdio.h>
// #include<unistd.h>
// int main()
// {
// 	printf("\nName - Vipul Chauhan\nSection - A\nStudent id - 20011016\n\n");
// 	int e_sum=0,o_sum=0,n;
// 	printf("Enter the size of an array : ");
// 	scanf("%d",&n);
// 	int arr[n];
// 	printf("Enter %d numbers : ",n);
// 	for(int i=0;i<n;i++)
// 	{
// 		scanf("%d",&arr[i]);
// 	}
// 	int pid=fork();
// 	if(pid==0)
// 	{
// 		for(int i=0;i<n;i++)
// 		{
// 			if(arr[i]%2 != 0)
// 				o_sum+=arr[i];
// 		}
// 		printf("Sum of Odd Numbers = %d\n", o_sum);
//  	}
//  	else
//  	{
//  		for(int i=0;i<n;i++)
// 		{
// 			if(arr[i]%2 == 0)
// 				e_sum+=arr[i];
// 		}
// 		printf("Sum of Even Numbers = %d\n", e_sum);
//  	}
// 	return 0;
// }
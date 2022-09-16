#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("\nName – Prahlad Singh Aswal \nSection - A ");
    printf("\nStudent ID - 20011854\n\n");
    
    int e_sum = 0, o_sum = 0; 
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements of the array: ");
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int pid = fork();
    if (pid == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 != 0)
                o_sum += arr[i];
        }
        printf("Sum of all Odd Numbers in array: %d\n\n", o_sum);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
                e_sum += arr[i];
        }
        printf("\nSum of all Even Numbers: %d\n", e_sum);
    }

    return 0;
}

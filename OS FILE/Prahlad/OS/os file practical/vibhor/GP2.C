#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("\n Name- Gajendra Babu \n Sec- A \n Student Id- 2018337 \n");
    int arr[5] = {2, 34, 54, 67, 78};
    int sum_odd = 0, sum_even = 0;
    int P_id;
    P_id = fork();

    // Parent process 
    if (P_id> 0)
    {
        for (int i = 0; i < 5; i++)
        {
            if (arr[i] % 2 == 0)
                sum_even = sum_even + arr[i];
        }
        printf("\nParent process \n");
        printf("Even sum=%d\n", sum_even);
    }

    // Child process 
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (arr[i] % 2 != 0)
                sum_odd = sum_odd + arr[i];
        }
        printf("Child process \n");
        printf("Odd sum =%d\n", sum_odd);
    }
    return 0;
}

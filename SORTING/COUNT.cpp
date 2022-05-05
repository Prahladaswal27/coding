
#include<iostream>
using namespace std;

void count(int *arr,int n)
{
     int max;
    max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    int count[max+1];

    for(int i=0;i<=max;i++)
    {
        count[i] = 0;

    }

    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    int i=0,j=0;
    while(i<=max)
    {
        if(count[i] > 0)
        {        
            arr[j] = i;
            count[i]--;
            j++;
        }

        else
        {
            i++;
        }
    }
}

int main()
{
     int arr[] = {1, 5, 3, 6, 9, 7, 8, 12, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\n\nBefore sort\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    count(arr, n);

    cout << "\n\nAfter sort\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}









// #include <iostream>
// using namespace std;

// void count(int arr[], int n)
// {
//     int max, output[n + 1];
//     max = arr[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] > max)
//             max = arr[i];
//     }

//     int count[max + 1];

//     for (int i = 0; i <= max; i++)
//     {
//         count[i] = 0;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         count[arr[i]]++;
//     }

//     for (int i = 1; i <= max; i++)
//     {
//         count[i] += count[i - 1];
//     }

//     for (int i = n - 1; i >= 0; i--)
//     {
//         output[count[arr[i]] - 1] = arr[i];
//         count[arr[i]]--;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = output[i];
//     }
// }

// int main()
// {
//     int arr[] = {1, 5, 3, 6, 9, 7, 8, 12, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << "\n\nBefore sort\n";
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << "\n";

//     count(arr, n);

//     cout << "\n\nAfter sort\n";
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

void bubble(int *arr, int n)
{
    int temp;
    int i, j, s = 0;
    for (int i = n-1; i >=0; i--)
    {
        cout << "\n"
             << i;
        s = 1;
        for (int j = n-1; j >0; j--)
        {
            if (arr[j] > arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                s = 0;
            }
        }
        if (s == 1)
            break;
    }
}

int main()
{
      int arr[] = {23,67,98,34,56,12,76,45,88};
    // int arr[] = {10, 12, 34, 56, 78, 89};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\n\nBefore sort\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    bubble(arr, n);

    cout << "\n\nAfter sort\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
        1. stable               - yes
        2. inplace or outplace  - inplace
        3. time complexity      - worst case- O(n^2),   average case- O(n^2),   best case- O(n)
        4. space complexity     - O(1)
        5. adapative            - no ( but we can make bubble sort adapative)
        6.


*/

// #include<iostream>
// using namespace std;

// void printarray(int arr[],int n)
// {
//     for (int  i = 0; i < n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }

// }

// void bubble_sort(int arr[],int n)
// {
//     int temp;
//     int s = 0;
//     for (int  i = 0; i < n-1; i++)
//     {
//         cout<<"\n\nno of passes: "<<i+1;
//         s= 1;
//         for (int j = 0; j < n-1-i; j++)
//         {
//             if(arr[j] > arr[j+1])
//             {
//                  temp;
//                 temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//                 s = 0;
//             }
//         }
//         if(s==1)
//         return ;

//     }

// }
// int main()
// {
//     int n;
//     cout<<"\n\nEnter the size of the array: ";
//     cin>>n;

//     int arr[n];
//     cout<<"\n\nEnter the element of the array: ";
//     for (int  i = 0; i < n; i++)
//     {
//         cin>>arr[i];

//     }

//     cout<<"\n\nArray before sorted: ";
//     printarray(arr,n);

//     bubble_sort(arr,n);
//     cout<<"\n\nArray after sorted: ";
//     printarray(arr,n);

//     return 0;

// }

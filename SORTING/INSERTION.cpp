
#include <iostream>
using namespace std;

void insertion(int arr[], int n)
{
    int i, j, temp;
    int key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {21, 56, 34, 98, 77, 125, 38, 55, 10, 4, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\n\nBefore sorting\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    insertion(arr, n);

    cout << "\n\nAfter sorting\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
    1.  stable = yes
    2.  inplace or outplace = inplace
    3.  time complexity = worst case- O(n^2),   average case- O(n^2),   best case- O(n)
    4.  space complexity = O(1)
    5.  adapative = yes
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

// void insertion_sort(int arr[],int n)
// {
//    int i,j;
//    int s=0,c=0;
//     int key;
//    for(int i=1;i<n;i++)
//    {
//        key = arr[i];
//        j = i-1;
//        c++;
//        while(j>=0 && arr[j] > key)
//        {
//            s++;
//            arr[j+1] = arr[j];
//             j--;

//        }
//        arr[j+1] = key;
//    }

//     cout<<"\nNo of comp: "<<c;
//     cout<<"\nnp of shift: "<<s+n-1;
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

//     insertion_sort(arr,n);
//     cout<<"\n\nArray after sorted: ";
//     printarray(arr,n);

//     return 0;

// }

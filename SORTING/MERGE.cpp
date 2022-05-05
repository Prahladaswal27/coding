#include<iostream>
using namespace std;

void merge(int *arr,int mid,int low,int high)
{
    int i=low,k=low;
    int a[100];

    int j = mid+1;

    while(i<=mid  && j<=high)
    {
        if(arr[i] < arr[j])
        {
            a[k] = arr[i];
            k++;
            i++;
        }

        else
        {
            a[k] = arr[j];
            k++;
            j++;
        }
    }

        while(i<=mid)
        {
            a[k] = arr[i];
            k++;
            i++;
        }

        while(j<=high)
        {
            a[k] = arr[j];
            k++;
            j++;
        }

        for(int i=low;i<=high;i++)
        {
            arr[i] = a[i];
        }
    

}

void mergesort(int arr[],int low,int high)
{
    int mid;

    if(low<high)
    {
        int mid = (low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);

        merge(arr,mid,low,high);
    }

}


int main()
{
    int arr[] = {12,6,89,146,22,67,49,34,55,99,143,27};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "\n\nBefore sort\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    mergesort(arr, 0, n - 1);

    cout << "\n\nAfter sort\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}



/*
    1.  stable =  stable
    2.  inplace or outplace = outplace
    3.  time complexity :-   best case: O(nlogn),  worst case= O(nlogn),    average case = O(nlogn)
    4.  space complexity = O(n)
    5.  adapative = no
*/


















// #include<stdio.h>

// void printarray(int arr[],int n)
// {
//     for (int  i = 0; i < n; i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
// }

// void merge(int A[], int mid, int low, int high)
// {
//     int i, j, k, B[100];
//     i = low;
//     j = mid + 1;
//     k = low;

//     while (i <= mid && j <= high)
//     {
//         if (A[i] < A[j])
//         {
//             B[k] = A[i];
//             i++;
//             k++;
//         }
//         else
//         {
//             B[k] = A[j];
//             j++;
//             k++;
//         }
//     }
//     while (i <= mid)
//     {
//         B[k] = A[i];
//         k++;
//         i++;
//     }
//     while (j <= high)
//     {
//         B[k] = A[j];
//         k++;
//         j++;
//     }
//     for (int i = low; i <= high; i++)
//     {
//         A[i] = B[i];
//     }
// }

// void mergeSort(int A[], int low, int high)
// {
//     int mid;
//     if (low < high)
//     {
//         mid = (low + high) / 2;
//         mergeSort(A, low, mid);
//         mergeSort(A, mid + 1, high);
//         merge(A, mid, low, high);
//     }
// }


// int main()
// {
//     // int A[] = {9, 14, 4, 8, 7, 5, 6};
//     int A[] = {9, 1, 4, 14, 4, 15, 6};
//     int n = 7;
//     printarray(A, n);
//     mergeSort(A, 0, 6);
//     printarray(A, n);
//     return 0;
// }

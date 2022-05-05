#include <iostream>
using namespace std;

int binary_search(int arr[], int h, int l, int k)
{
    int mid;

    if(l<=h)
    {
        mid = (l+h)/2;

        if(arr[mid] == k)
        {
            return mid;
        }

        if(arr[mid] < k)
        {
            return binary_search(arr,h,mid+1,k);
        }

        else
        {
           return  binary_search(arr,mid-1,l,k);
        }
    }

    return -1;
}

int main()
{
    int n;
    cout << "\nEnter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "\n\nEnter the element of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "\n\nEnter the element you want to fint: ";
    cin >> key;

    int indexf = binary_search(arr, n - 1, 0, key);

    if (indexf == -1)
        cout << "\n\nElement not found";
    else
        cout << "\n\nElement found at: " << indexf << " index";

    return 0;
}

// #include<iostream>
// #include <iostream>
// using namespace std;

// int binary_search(int arr[] , int n, int ele)
// {
//     int low,high,mid;
//     low = 0;
//     high = n-1;

//     while(low<=high)
//     {
//         mid = (low+high)/2;
//         if(arr[mid] == ele)
//         {
//             return mid;
//         }

//         if(arr[mid] < ele)
//         {
//             low = mid + 1;
//         }
//         else
//         {
//             high = mid - 1;
//         }
//     }

//     return -1;

// }

// int main()
// {
//     int t;
//     cout << "\nEnter the no. of test cases: ";
//     cin >> t;
//     for (int i = 0; i < t; i++)
//     {
//         int n;
//         cout << "\nEnter the size of the array: ";
//         cin >> n;

//         int arr[n];
//         cout << "\n\nEnter the element of the array: ";
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }
//         int key;
//         cout << "\n\nEnter the element you want to fint: ";
//         cin >> key;

//         int indexf = binary_search(arr, n, key);

//         if (indexf == -1)
//             cout << "\n\nElement not found";
//         else
//             cout << "\n\nElement found at: " << indexf << " index";
//     }
//     return 0;
// }

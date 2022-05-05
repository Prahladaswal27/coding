#include <iostream>
using namespace std;

int parition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp;
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quick(int *arr, int low, int high)
{
    int partitonindex;
    if (low < high)
    {
        partitonindex = parition(arr, low, high);
        quick(arr, low, partitonindex - 1);
        quick(arr, partitonindex + 1, high);
    }
}

int main()
{
    int arr[] = {12, 65, 28, 55, 49, 187, 78, 65};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\n\nBefore sort\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    quick(arr, 0, n - 1);

    cout << "\n\nAfter sort\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}


/*
    1.  stable = not stable
    2.  inplace or outplace = inplace
    3.  time complexity :-   best case: O(nlogn),  worst case= O(nlogn),    average case = O(n^2)
    4.  space complexity = O(nlogn)
    5.  adapative = no
*/






// #include <iostream>
// using namespace std;

// void printarray(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }

// int partition(int arr[], int low, int high)
// {
//     int pivot = arr[low], temp;
//     int i = low + 1;
//     int j = high;

//     do
//     {
//         while (arr[i] < pivot)
//         {
//             i++;
//         }

//         while (arr[j] > pivot)
//         {
//             j--;
//         }

//         if (i < j)
//         {
//             temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//     } while (i < j);

//     temp = arr[low];
//     arr[low] = arr[j];
//     arr[j] = temp;

//     return j;
// }

// void quick_sort(int arr[], int low, int high)
// {
//     int partitionindex;

//     if (low < high)
//     {
//         partitionindex = partition(arr, low, high);
//         quick_sort(arr, low, partitionindex - 1);
//         quick_sort(arr, partitionindex + 1, high);
//     }
// }
// int main()
// {
//     int n;
//     cout << "\n\nEnter the size of the array: ";
//     cin >> n;

//     int arr[n];
//     cout << "\n\nEnter the element of the array: ";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     cout << "\n\nArray before sorted: ";
//     printarray(arr, n);

//     quick_sort(arr, 0, n - 1);
//     cout << "\n\nArray after sorted: ";
//     printarray(arr, n);

//     return 0;
// }

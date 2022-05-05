#include <iostream>
using namespace std;

int parition(int arr[], int low, int high)
{
    int pivotindex = low + rand()%(high - low+1);
    int i = low - 1;

    int pivot = arr[pivotindex];

    int temp = arr[pivotindex];
    arr[pivotindex] = arr[high];
    arr[high] = temp;
    
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
    temp;
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



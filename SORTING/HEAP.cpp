#include <iostream>
using namespace std;

void heapify(int arr[],int n,int i)
{
    int largest = i;
    int left = 2*i+1,right = 2*i + 2;

    if(left<n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right < n && arr[right] > arr[largest])
    {
        largest = right;

    }
    if(largest!= i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr,n,largest);
    }

}

void heap(int arr[],int n)
{
    for (int  i = n/2-1; i >=0;i--)
    {
        heapify(arr,n,i);

    }

    int temp;

    for(int i=n-1;i>=0;i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr,i,0);
    }
    
    
}

int main()
{
    // int arr[] = {12, 65, 28, 55, 49, 187, 78, 65};
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\n\nBefore sort\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    heap(arr,n);

    cout << "\n\nAfter sort\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

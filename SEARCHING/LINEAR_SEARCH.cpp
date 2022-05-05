
#include <iostream>
using namespace std;

int linear_search(int arr[] , int n, int ele)
{
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == ele)
            return i;
    }

    return -1;
    
}

int main()
{
    int t;
    cout << "\nEnter the no. of test cases: ";
    cin >> t;
    for (int i = 0; i < 3; i++)
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
        cout << "\n\nEnter the element you want to found: ";
        cin >> key;

        int indexf = linear_search(arr, n, key);

        if (indexf == -1)
            cout << "\n\nElement not found"; 
        else 
            cout << "\n\nElement found at: " << indexf << " index";
    }
    return 0;
}

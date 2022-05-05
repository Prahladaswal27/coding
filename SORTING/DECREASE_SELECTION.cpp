#include<iostream>
using namespace std;

void selection(int *arr,int n)
{
    int i,j,temp,indexmin;

    for(int i=n-1;i>=0;i--)
    {
        indexmin = i;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j] < arr[indexmin])
                indexmin = j;
        }

        temp = arr[i];
        arr[i] = arr[indexmin];
        arr[indexmin] = temp;
    }

}

int main()
{
    int arr[] = {12,87,7,68,39,176,189,34,27,55};
    int n = sizeof(arr)/sizeof(arr[0]);

     cout<<"\n\nBefore sorting\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    selection(arr,n);

    cout<<"\n\nAfter sorting\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}


/*
    1.  stable = not stable(but we can make stable)
    2.  inplace or outplace = inplace
    3.  time complexity :-   best case: O(n^2),  worst case= O(n^2),    average case = O(n^2)
    4.  space complexity = O(1)
    5.  adapative = no
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

// void selection_sort(int arr[],int n)
// {
//    int indexmin,temp;
//    for(int i=0;i<n;i++)
//    {
//        indexmin = i;
//        for(int j=i+1;j<n;j++)
//        {
//            if(arr[j] < arr[indexmin])
//             indexmin = j;
//        }

//        temp = arr[i];
//        arr[i] = arr[indexmin];
//        arr[indexmin] = temp;
//    }
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

//     selection_sort(arr,n);
//     cout<<"\n\nArray after sorted: ";
//     printarray(arr,n);
    
//     return 0;

// }

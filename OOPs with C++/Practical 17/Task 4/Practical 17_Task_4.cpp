
#include <bits/stdc++.h>
using namespace std;

void print_Vector(vector<int> v)
{
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << "\n";
}

void print_Array(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}
int main()
{
    // creating a Array
    int arr[] = {27, 77, 54, 12, 89, 39, 36, 77};
    
    // 1st part- Converting a array into vector
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vec(arr, arr + n);
    
    // 2nd part- sorting an vector
    cout << "\nPrinting vector before sorting : \n";
    print_Vector(vec);
    sort(vec.begin(), vec.end());
    cout << "\nPrinting vector after sorting : \n";
    print_Vector(vec);
    
    // 3rd part- Reversing a vector
    reverse(vec.begin(), vec.end());
    cout << "\nPrinting vector after Reversing : \n";
   print_Vector(vec);
    
    //4th and 5th part of task
    cout << "\nPrinting max and min element of vector : \n";
    cout << "Max element is : " << *(max_element(vec.begin(), vec.end())) 
        << " Min Element of vector is : " << *(min_element(vec.begin(), vec.end())) << endl;
    
    //6th part- counting  occurrence of an element
    cout << "\noccurrence of an 77 in vector :" << count(vec.begin(), vec.end(), 77) << endl;
    sort(arr, arr + n);

    // 7th part- sort an array
    cout << "\nPrinting array after sorting :\n";
   print_Array(arr, n);
    
    //8th part- binary search in an array
    cout << "\nUsing Binary Search for finding 70 in an Array: ";
    if (binary_search(arr, arr + n, 70))
    {
        cout << "70 Exist in the Array \n"<<endl;
    }
    else
    {
        cout << "70 Doesn't Exist in the Array\n"<<endl;
    }
  
    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

// function for printing the elements in a vector
// B part of task
void print_Vector(vector<int> v)
{
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << "\n";
}

int main()
{
    vector<int> v;
    int n;
    cout << "\nEnter the size of the vector: ";
    cin >> n;
    cout<<"Enter the element in vector: ";
    // A part of task
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    cout<<"Element in vector are: ";
   print_Vector(v);
    
    // C part of Task
    cout << "\nSize of the vector is : " << v.size()
         << "\t Capacity of vector is : " << v.capacity() << "\n";
    
    // D part of Task
    v.resize(2 * n, 0);
    cout<< "\nPrinting vector after resizing and intialising after 0\n";
   print_Vector(v);
    
    // E part of Task
    cout << "\nChecking vector is empty or not after : ";
    if (v.empty())
        cout << "Vector is empty\n"<<endl;
    else
        cout << "Vector is not empty\n"<<endl;
    
    return 0;
}

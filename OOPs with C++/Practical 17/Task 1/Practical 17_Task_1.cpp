
#include <iostream>
#include <list>
#include <iterator>
using namespace std;

// function for printing the elements in a list
// a part of the task 

void print_List(list<int> g)
{
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << *it << " ";
    cout << "\n";
}

int main()
{
    list<int> l;
    int n;
    cout << "\nEnter the size of the List: ";
    cin >> n;
    cout<<"Enter the element of list: ";
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        l.push_back(ele);
    }

    cout<<"List is: ";
   print_List(l);
    // B part of Task
    cout << "\nSize of the list is : " << l.size() << "\n";

    // C part of Task
    l.sort();
    cout << "\nPrinting list after sorting\n";
   print_List(l);
    
    // D part of Task
    l.reverse();
    cout << "\nPrinting list after Reversing\n";
   print_List(l);
    
    return 0;
}

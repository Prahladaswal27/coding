
#include <iostream>
using namespace std;

void swap(int *a, int *b); // function declaration
int main()
{
    int a = 10, b = 20;

    cout << "\nBefore swap function" << endl;
    cout << "a= " << a << " b= " << b << endl;

    swap(&a, &b); // function call
    // pass arguments call by reference

    cout << "\nAfter swap function" << endl;
    cout << "a= " << a << " b= " << b << endl;

    return 0;
}

void swap(int *a, int *b)  // function definition
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

    cout << "\nValues is swap function" << endl;
    cout << "a= " << *a << " b= " << *b << endl;
}

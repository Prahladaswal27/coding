
#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *p;
    int **q;

    p = &a;  //pointer p stores address of variable a
    q = &p; //pointer q stores  address of pointer p

    cout << *p << endl;  //print value of a
    cout << **q << endl; //print value of a

    **q = **q / 5;  // divide value of a by 5

    cout << "Value of **q is: " << **q << endl;  // print new value of a
    cout << "Value of a is: " << a << endl;    // print new value of a

    return 0;
}

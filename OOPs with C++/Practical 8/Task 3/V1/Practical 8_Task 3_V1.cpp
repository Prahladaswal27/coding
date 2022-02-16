
#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *p;
    int **q;

    p = &a; //pointer p stores address of variable a
    q = &p; //pointer q stores  address of pointer p

    cout << *p << endl; //print value of a
    cout << "\n";

    cout << **q << endl; // print value of a
    return 0;
}

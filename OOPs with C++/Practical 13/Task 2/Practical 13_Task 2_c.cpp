#include <iostream>
#include <string>
using namespace std;

class Base
{
    public:
    virtual int add(int a, int b) // due to virtual keyword complier will ignore it during compile time
    {
        cout<<"\nBase class add function"<<endl;
        return a + b;
    }
    virtual int multi(int a, int b) = 0; // due to abstraction complier will not bind this function at compile time  it will bind during runtime
};

class Derived : public Base
{
    public:
    int add(int a, int b) //  during runtime this definition will be followed
    {
        cout<<"\nChild class add function"<<endl;
        return a + b + 1;
    }

    int multi(int a, int b)
    {
        cout<<"\nBase class multi virtual function"<<endl;
        return a * b;
    }
};

int main()
{
    Base *ptr;
    Derived c;
    ptr = &c;
    cout << endl
         << "Abstraction was in the Base class in the Above implementation and not in the Derived" << endl
         << "class because pure virtual func of Base was defined in Derived class\n" << endl;

    return 0;
}

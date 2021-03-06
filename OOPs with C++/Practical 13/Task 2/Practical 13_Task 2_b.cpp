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
    cout << ptr->multi(10, 20)<<"\n"<<endl;

    return 0;
}

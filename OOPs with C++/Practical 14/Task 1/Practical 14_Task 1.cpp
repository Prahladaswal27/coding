
#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    virtual int add(int a, int b)
    {
        cout<<"\nBase class add method"<<endl;
        return a + b;
    }

    int multi(int a, int b)
    {
        cout<<"\nBase class multi method"<<endl;
        return a * b;
    }
};

class Derived : public Base
{
public:
    int add(int a, int b)
    {
        cout<<"\nDerived class add method"<<endl;
        return a + b + 1;
    }

    int multi(int a, int b)
    {
        cout<<"\nDerived class mutli method"<<endl;
        return a / b;
    }
};

int main()
{
    Base *p;
    Derived c;
    p = &c;
    cout << p->multi(5, 10) << " "; // early binding (compile time binding)
    cout << p->add(10,20)<<"\n"<<endl;          // late binding (run time binding)

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class base
{
public:
    base()
    {
        cout << "\nBase class constructor" << endl;
    }
    virtual ~base()
    {
        cout << "\nBase class destructor" << endl;
    }
};

class Derived : public base
{
public:
   Derived()
    {
        cout << "\nDerived class constructor" << endl;
    }
    ~Derived()
    {
        cout << "\nDerived class destructor" << endl;
    }
};

int main()
{
    base *ptr;
    Derived c;
    ptr = &c;
    delete ptr;

    return 0;
}

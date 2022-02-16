
#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "\nBase class constructor" << endl;
    }
    ~Base()
    {
        cout << "\nBase class destructor" << endl;
    }
};

class Derived : public Base
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
    Base *ptr;
    Derived c;
    ptr = &c;
    delete ptr;         // Base desturctor, Derived destructor, Base destructor
    // ptr->~Base();    BC CC BD CD BD  
    // ptr->~Derived();  error: the type being destroyed is 'Base', but the destructor refers to 'Derived'

    return 0;
}

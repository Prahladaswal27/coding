
#include <iostream>
using namespace std;
class A
{
public:
    A()
    {
        cout << "\nExecution of Class A Constructor" << endl;
    }
    ~A()
    {
        cout << "\nExecution of Class A Destructor" << endl;
    }
};
class B : public A
{

public:
    B()
    {
        cout << "\nExecution of Class B Constructor" << endl;
    }
    ~B()
    {
        cout << "\nExecution of Class B Destructor" << endl;
    }
};
class C : public B
{
public:
    C()
    {
        cout << "\nExecution of Class C Constructor" <<"\n"<<endl;
    }
    ~C()
    {
        cout << "\nExecution of Class C Destructor" << endl;
    }
};
int main()
{
    C obj;
    // cout << "calling of Class A Destructor" << endl;
    // obj.~A();
    // cout << endl
    //      << "calling of Class B Destructor" << endl;
    // obj.~B();
    // cout << endl
    //      << "calling of Class C Destructor" << endl;
    // obj.~C();
    // cout << endl
    //      << "Default Destructor called as Program Ends" << endl;

    return 0;
}

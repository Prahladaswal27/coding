#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "\nExecution of Class A Constructor" << endl;
    }
};
class B : public A
{

public:
    B()
    {
        cout << "\nExecution of Class B Constructor" << endl;
    }
};
class C : public B
{

public:
    C()
    {
        cout << "\nExecution of Class C Constructor" <<"\n"<<endl;
    }
};
int main()
{
    cout << "\nCalled Constructor of C" << endl
         << "............." << endl;
    C obj;

    return 0;
}

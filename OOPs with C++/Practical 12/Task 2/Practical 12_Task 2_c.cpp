
#include <iostream>
using namespace std;
class A
{
public:
    int a;
    A(int count)
    {
        a = count;
        cout << "\na = " << a << endl;
    }
};

class B : public A
{

public:
    int b;
    B(int count):A(count)
    {
        b = count;
        cout << "\nb = " << b << endl;
    }
};

class C : public B
{
    int c;

public:
    C(int count):B(count)
    {
        c = count;
        cout << "\nc = " << c << endl;
    }
};

int main()
{
    C obj(40);

    return 0;
}

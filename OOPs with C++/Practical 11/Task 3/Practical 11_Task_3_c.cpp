#include <iostream>
using namespace std;

class B
{

public:
    int k;
    void display_B()
    {
        cout << "k in B= " << k << endl;
    }
};

class C
{
public:
    int k;
    void display_c()
    {
        cout << "k in C = " << k << endl;
    }
};

class D : public B, public C
{
public:
    void display_D()
    {
        cout << "\nk of B and C inherited in D = " << B::k << " and " << C::k;
        cout<<"\n"<<endl;
    }
};

int main()
{
    D obj;
    obj.B::k = 50;
    obj.C::k = 100;
    obj.display_D();

    return 0;
}

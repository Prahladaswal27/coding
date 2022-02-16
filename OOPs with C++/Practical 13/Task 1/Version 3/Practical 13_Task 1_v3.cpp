#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    int add(int a, int b)
    {
        cout<<"\nBase class add func for integer"<<endl;
        return a + b;
    }
    float add(float a, float b)
    {
        cout<<"\nBase class add func for float"<<endl;
        return a + b;
    }
    string add(char a, char b)
    {
        cout<<"\nBase class add func for string"<<endl;
        string str;
        str = str + a;
        str = str + b;
        return str;
    }
};

class Derived : public Base
{
public:
    using Base::add;
    int add(int a, int b)
    {
        cout<<"\nDerived class add func for interger"<<endl;
        return a + b + 1;
    }
};

int main()
{
    Derived obj2;
    cout << "\nWithout using  " << endl
        <<"..........."<<endl;

    int ans1 = obj2.add(15, 25);
    cout<<ans1;

    float ans2 = obj2.add(8.5f, 3.15f);
    cout<<ans2<<"\n"<<endl;

    return 0;
        
}
/*
not visible functions
without using
base -int add(int,int)
      -float add(float ,float)
      -string add(char,char)
*/


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
    int add(int a, int b)
    {
        cout<<"\nDerived class add func for interger"<<endl;
        return a + b + 1;
    }
};

int main()
{
    Base obj1;
    Derived obj2;
    
    int ans1 = obj1.add(1, 2);
    cout << "\nOverriding func called from Base class= " << ans1 << endl;

    int ans2 = obj2.add(1, 2);
    cout<<"\noverriding fun called from Derived class= " << ans2;

    return 0;

}

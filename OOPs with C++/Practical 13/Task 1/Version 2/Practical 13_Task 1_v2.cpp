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

class Child : public Base
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
    Child obj2;
    cout << "\nWith using " << endl
         << "............."<<endl;

    int ans1 = obj2.add(15, 25);
    cout<< ans1 << endl;

    float ans2 = obj2.add(8.5f, 3.15f);
    cout<< ans2 << endl;

    string ans3 = obj2.add('a', 'b');
    cout<<ans3<<"\n"<<endl;

    return 0;
}
/*
not visible functions
with using
Base-add(int ,int)
*/

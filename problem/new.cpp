
#include<bits/stdc++.h>
using namespace std;

class B;
class A
{
    private:
       int a;
    public:

    A(int a)
    {
        this->a=a;
    }

    friend void operator||(A obj1,B obj2);

};

class B
{
    private:
       int b;
    public:

    B(int b)
    {
        this->b=b;
    }

    friend void operator||(A obj1,B obj2);

};

void operator||(A obj1,B obj2)
{
    if(obj1.a || obj2.b)
    {
        cout<<"\nTrue";
    }
    else
    {
        cout<<"\nfalse";
    }
}

int main()
{
   int a,b;
   cin>>a>>b;

   A o1(a);
   B o2(b);

   o1 || o2;

   return 0;
}

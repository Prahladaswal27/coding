#include<iostream>
using namespace std;


void tower(int n,int a,int b,int c)
{
    if (n==1)
    {
        cout<<"\nmove "<<a<<" to "<<b;
        return;
    }
    tower(n-1,a,c,b);
    cout<<"\nmove "<<a<<" to "<<b;
    tower(n-1,c,b,a);
    return ;


}
int main()
{
    int a=1,b=2,c=3;

    int n;
    cin>>n;
    tower(n,a,b,c);
    return 0;
}

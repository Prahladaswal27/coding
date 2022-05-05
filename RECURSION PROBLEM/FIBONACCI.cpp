#include<iostream>
using namespace std;

int fibonacciseries(int n)
{
    if(n==1)
        return 0;
    
    else if(n==2)
        return 1;

    else
        return fibonacciseries(n-1) + fibonacciseries(n-2);

}


int main()
{
    int n;
    cout<<"\n\nEnter the no. of terms: ";
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cout<<fibonacciseries(i)<<" ";
    }
    return 0;
}

// void fibonacciseries(int n)
// {
//     int x=0,y=1,z;

//     if(n==1)
//     {
//        cout<<x<<" ";
//        return ;
//     }
//     if(n==2)
//     {
//         cout<<x<<" "<<y;
//         return ;
//     }

//     cout<<x<<" "<<y<<" ";
    
//     for(int i =3;i<=n;i++)
//     {
//         z =x+y;
//         cout<<z<<" ";
//         x=y;
//         y=z;
//     }
// }
// int main()
// {
//     int n;
//     cout<<"\n\nEnter the no. of terms: ";
//     cin>>n;

//     fibonacciseries(n);
//     return 0;
// }


#include<iostream>
using namespace std;

int factorial(int);

int main()
{
   int n,res;
   
   cout<<"\nEnter the number: ";
   cin>>n;
   
   res=factorial(n);
   
   cout<<"\nFactorial of "<<n<<" is: "<<res<<endl;
   
   return 0;

}

int factorial(int num)
{
   int i,fact=1;
   
   for(i=1;i<=num;i++)
   {
       fact=fact*i;
   }
   
   return fact;

}

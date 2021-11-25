
#include<iostream>
using namespace std;

int main()
{
   int a=10;
   int *p;
   int **q;
   
   p=&a;
   q=&p;
   
   cout<<*p<<endl;
   cout<<**q<<endl;
   
   **q=**q/5;
   
   cout<<"Value of **q is: "<<**q<<endl;
   cout<<"Value of a is: "<<a<<endl;
   
   return 0;
   
}


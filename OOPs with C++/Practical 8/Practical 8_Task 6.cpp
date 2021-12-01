
#include<iostream>
#include<math.h>

using namespace std;

void series(int n);

int main()
{
   int n;
   cout<<"\nEnter last term: ";
   cin>>n;
   
   cout<<"\nSeries is\n";
   series(n);
   
   cout<<endl;
   return 0;
   
}

void series(int n)
{
   if (n==1)
      {
          cout<<2<<" ";
          return ;    
      }
   else
      {
          series(n-1);
          cout<<(pow(n,n) + n)<<" ";
        
      }
      
}




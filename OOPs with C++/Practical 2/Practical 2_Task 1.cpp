
#include<iostream>
using namespace std;

int main()
{
   int n,i,count=0;
  cout<<"Enter the no.: ";
  cin>>n;
  
  for(i=2:i<=n/2;i++)
  {
    if(n%i==0)
    {
      count =1;
      break;
    }
  }
  
  if(n==1)
    cout<<"\n1 is neither prime nor composite";
  else
  {
    if(count==0)
        cout<<n<<" is prime no.";
    else
         cout<<n<<" is not a prime no.";
  }
  
  return 0;
  
}
    

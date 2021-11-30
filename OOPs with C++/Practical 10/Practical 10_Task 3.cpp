
#include<iostream>
using namespace std;

class remainder
{
   private:
      int a,b;
      
   public:
      remainder(int a,int b)
      {
         this->a=a;
         this->b=b; 
      }
      
      int res()
      {
         return(a%b);
      }
      
};

int main()
{
    int a,b;
    cout<<"\nEnter the two no.: ";
    cin>>a>>b;
    
    remainder r(a,b);
    cout<<"\nRemainder of two no. is: "<<r.res()<<endl;
    
    return 0;
    
}

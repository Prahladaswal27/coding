
#include<iostream>
using namespace std;

class test2;
class test1
{
   int a;
   public: 
      void get()
      {
          cout<<"\nEnter the value of a: ";
          cin>>a;
      }
      
      friend void operator <(test1,test2);
};

class test2
{
   int b;
   public:
     void get()
     {
        cout<<"\nEnter the value of b: ";
        cin>>b;
     }
     
     friend void operator <(test1,test2);
};


void operator <(test1 obj1,test2 obj2)
{
   if(obj1.a<obj2.b)
   {
       cout<<"\na is less than b"<<endl;
   }
   
   else 
   {
      cout<<"\nb is less than a"<<endl;
   }
}

int main()
{
   test1 obj1;
   test2 obj2;
   
   obj1.get();
   obj2.get();
   
   obj1<obj2;
    
   return 0;
   }
         


#include<iostream>
using namespace std;

class area
{
   private:
       int len,wid,side;
   public:
     area(int l,int w)
     {
        len=l;
        wid=w;
        print_area(len,wid);
     }
     
     area(int s)
     {
         side=s;
         print_area(side);
     }
     
     void print_area(int l,int w)
     {
         float ar;
         ar=l*w;
         cout<<"\nArea of rectangle is: "<<ar<<endl;
     }
     
     void print_area(int s)
     {
         float ar2;
         ar2=s*s;
         cout<<"\nArea of square is: "<<ar2<<endl;
     }
     
};

int main()
{
   int l,w,s;
   
   cout<<"\nEnter the length and width of rectangle: ";
   cin>>l>>w;
   cout<<"\nEnter the side of the square: ";
   cin>>s;
   
   area obj(l,w);
   area obj2(s);
   
   return 0;
   
}


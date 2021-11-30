
#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
   cout<<"\nUSE OF endl"<<endl;
   cout<<"GEHU"<<endl<<"DEHRADUN"<<endl<<"UTTARAKHAND"<<endl;
   
   cout<<"\nUSE OF setw()\n";
   cout<<setw(8)<<"DEHRADUN"<<endl;
   
   cout<<"\nUSE OF setfill()\n";
   cout<<setw(12)<<setfill('*')<<"DEHRADUN"<<endl;
   
   return 0;
   
}


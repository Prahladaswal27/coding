
#include<iostream>
#include<string>

using namespace std;

class info
{
   private:
      string name,hof;
      char add[20];
      long int phn_no,mob_no;
      
   public:
   
      void get_data(int i)
         {
               cout<<"\nEnter the "<<i+1<<" student name: ";
               cin>>name;
               cout<<"Enter the "<<i+1<<" student address: ";
               cin>>add;
               cout<<"Enter the "<<i+1<<" student telephone number: ";
               cin>>phn_no;
               cout<<"Enter the "<<i+1<<" student mobile number: ";
               cin>>mob_no;
               cout<<"Enter the head of the family: ";
               cin>>hof;
               
         }
         
         void print_data(int i)
         {
               cout<<"\n   Student details     "<<endl;
               
               cout<<"\nStudent "<<i+1<<" name: "<<name;
               cout<<"\nStudent "<<i+1<<" address: "<<add;
               cout<<"\nStudent "<<i+1<<" phone no: "<<phn_no;
               cout<<"\nStudent "<<i+1<<" mobile no: "<<mob_no;
               cout<<"\nHead of the family: "<<hof<<endl;
               
         }
         
};

int main()
{
   int n;
   cout<<"\nEnter the total no. of students: ";
   cin>>n;
   
   info s[n];
   
   for(int i=0;i<n;i++)
   {
       s[i].get_data(i);
   }
   
   for(int i=0;i<n;i++)
   {
      //cout<<endl;
      s[i].print_data(i);
   }
   
   return 0;
   
}

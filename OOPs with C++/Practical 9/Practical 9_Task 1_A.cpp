
#include<iostream>
#include<string>

using namespace std;


class student
{
    public:
         
          string add;
          int roll_no;
          long int phn_no;
         
         void print_data(string s)
         {
               cout<<"\n   Student details     "<<endl;
               
               cout<<"\nStudent name: "<<s;
               cout<<"\nStudent roll no: "<<roll_no;
               cout<<"\nStudent phone number: "<<phn_no;
               cout<<"\nStudent address: "<<add<<endl;
         }
             
};

int main()
{
     student john,sam;
     
     john.roll_no=2018554;
     john.phn_no=9123846345;
     john.add="15 george street,california,USA";
     
     sam.roll_no=2018559;
     sam.phn_no=9875219053;
     sam.add="17 peter street,california,USA";
     
     
     john.print_data("John");
     sam.print_data("Sam");
}


   

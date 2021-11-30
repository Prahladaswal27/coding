
#include<iostream>
#include<string>

using namespace std;

class student
{
    private:
       string name;
       int mark,age;
       
    public:
         
         void get_data(int i)
         {
               cout<<"\nEnter the "<<i+1<<" student name: ";
               cin>>name;
               cout<<"Enter the "<<i+1<<" student age: ";
               cin>>age;
               cout<<"Enter the "<<i+1<<" student marks: ";
               cin>>mark;
                 
         }
         
         friend int print_total(student s);
         
};

int print_total(student s)
{
    int sum=0;
    sum +=s.mark;
    return sum;
}

  
int main()
{
    int sum=0;
    student s[3];
    
    for(int i=0;i<3;i++)
     {
          s[i].get_data(i);
          
     }   
     
     for(int i=0;i<3;i++)
     {
         sum+= print_total(s[i]);
     } 
     
     cout<<"\nSum of all students marks is: "<<sum<<endl;
     return 0;
     
}  

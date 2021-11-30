
#include<iostream>
using namespace std;

class college
{
   private:
   string name;   /* Cannot access these members outside the class */
   int students;
    
   public:
   int marks;  /* Access these members outside the class */
   char sec;
      
};

struct student
{
   string name;  /* Access these members outside the structure */
   int ns;

};

int main()
{
  struct student s;
  college s2;
  
  return 0;
}
   

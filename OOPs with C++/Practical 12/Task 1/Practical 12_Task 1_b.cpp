
#include <iostream>

using namespace std;

class A

{

 private:

 int a;

 public:

 int b;

 protected:

 int c;

};

class B : public A

{

 public:

 void display()

 {

 cout << "\nb=" << b<<"\n"<<endl;

 }

};

int main()

{

 B obj;

 obj.b = 30;

 obj.display();

 return 0;

}

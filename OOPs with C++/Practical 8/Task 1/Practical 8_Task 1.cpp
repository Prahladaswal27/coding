
#include<iostream>
using namespace std;

int main()
{
    int *p={10,20,20}; /* Invalid show error 'p' requires one element in initializer  */
    
    cout<<*p<<endl;
    
    p++;
    cout<<*p;


    return 0;
    
}

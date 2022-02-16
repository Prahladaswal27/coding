
#include<iostream>
using namespace std;

int main()
{
    int arr[]={10,20,30};
    cout<<*arr<<endl;
    
    cout<<arr;
    arr++;   // Invalid 
    
    cout<<*arr;
    
    return 0;
    
} 

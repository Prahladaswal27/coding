#include<iostream>
using namespace std;

int main()
{
    int arr[]={10,20,30};
    cout<<*arr<<endl;  // print value at index 0
    
    cout<<arr<<endl; // print base address(address of index 0)
    
    cout<<*(arr+1)<<endl; // print value at index 1
    return 0;
    
}

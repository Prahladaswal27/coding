
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str="GEHU";
    cout<<&str<<endl;
    
    str[0]='J';
    cout<<&str<<endl;
    
    cout<<str<<endl;
    return 0;
    
}

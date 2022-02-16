
#include <iostream>
using namespace std;

int main()
{
    cout<<"\n"<<endl;

    try
    {
        throw 'a';
        
    }
    catch (int x)
    {
        cout << "\ncaught" << x << "\n"<<endl;
    }
    
    return 0;
}

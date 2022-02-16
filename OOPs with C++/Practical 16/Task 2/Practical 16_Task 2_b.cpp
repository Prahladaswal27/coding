
#include <iostream>
using namespace std;

int main()
{
    try
    {
        throw 'a';
    }
    catch (int x)
    {
        cout << "\ncaught" << x << "\n"<<endl;
    }
    // Here this Catch will be executed
    catch (...)
    {
        cout << "\nDefault Exception\n"<<endl;
    }
    return 0;
}
//The block catch(...) is used for catch all, when a data type of a thrown exception doesn't
//match with any other catch block, the code inside catch(...) is executed. Note that the implicit type conversion doesn't happen
//when exceptions are caught. The character 'a' is not automatically converted to int.

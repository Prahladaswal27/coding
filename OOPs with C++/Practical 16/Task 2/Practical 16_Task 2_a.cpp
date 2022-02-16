
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "\nEnter two numbers for division: ";
    cin >> a >> b;
    try
    {
        if (b == 0)
        {
            throw runtime_error("\nDenominator cannot be 0\nTry something else...!!\n");
        }
        else
        {
            cout << "\nResult = " << a / b << "\n"<<endl;
        }
    }
    catch (runtime_error &ptr)
    {
        cout << ptr.what() << "\n";
    }
    return 0;
}
// Since no matching catch handler is found,exception is uncaught,
// and the run-time call to std::terminate is made as for uncaught exception.


#include <iostream>
using namespace std;

void divide(int a, int b)
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

int main()
{
    int a, b;
    cout <<"\nEnter two numbers for division: ";
    cin >> a >> b;
    try
    {
        divide(a, b);
    }
    catch (runtime_error &ptr) 
    {
        cout << ptr.what() << "\n"; 
    }
    return 0;
}

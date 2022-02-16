
#include <iostream>
using namespace std;

int factorial(int); // function declaration

int main()
{
    int n, res;

    cout << "\nEnter the number: ";
    cin >> n;

    res = factorial(n);  // call function
    cout << "\nFactorial of " << n << " is: " << res << endl;
    return 0;
}

int factorial(int num)  // function definition
{
    if (num < 0)
        return -1;

    if (num == 0)
        return 1;

    else
    {
        return (num * factorial(num - 1));  // function call itself
    }
}


#include <iostream>
#include <math.h>

using namespace std; // function declaration
void series(int n);

int main()
{
    int n;
    cout << "\nEnter last term: ";
    cin >> n;

    cout << "\nSeries is\n";
    series(n);  // call function
    cout << endl;
    return 0;
}

void series(int n) // function definition
{
    if (n == 1)
    {
        cout << 2 << " ";
        return;
    }
    else
    {
        series(n - 1); // // recursive function
        cout << (pow(n, n) + n) << " ";  
    }
}

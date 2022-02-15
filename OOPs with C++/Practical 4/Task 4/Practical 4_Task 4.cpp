
#include <iostream>
using namespace std;

namespace first
{
    int add(int a, int b)
    {
        return (a + b);
    }
}

namespace second
{
    float add(float a, float b)
    {
        return (a + b);
    }
}

using namespace first;

int main()
{
    cout << "\nSum is: " << add(3, 3);  // call first namespace add function
    cout << "\nADD is: " << add(3.6, 7.8) << endl;  // call first namespace add function
    cout << "\naddition of two is: " << add(3, 4.7f);  // call first namespace add function

    return 0;
}

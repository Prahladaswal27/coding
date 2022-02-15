
#include <iostream>
using namespace std;

namespace first
{
    int add(int a, int b)    // add function in first namespace scope
    {
        return (a + b);
    }
}

namespace second
{
    float add(float a, float b)  // add function in first namespace scope
    {
        return (a + b);
    }
}

int main()
{
    int sum;
    float a;
    sum = first::add(3, 3);  // call add function of first namespace
    a = second::add(3.6, 7.8);  // call add function of second namespace

    cout << "\nSum is: " << sum;
    cout << "\nADD is: " << a;
    //cout<<"\n addition of two is: "<<add(3,4.7f);

    return 0;
}

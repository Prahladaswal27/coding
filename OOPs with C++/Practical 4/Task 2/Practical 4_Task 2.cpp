
// #include <iostream>
// using namespace std;

// namespace first
// {
//     int add(int a, int b)
//     {
//         return (a + b);
//     }
// }

// namespace second
// {
//     float add(float a, float b)
//     {
//         return (a + b);
//     }
// }

// using namespace first;
// int main()
// {
//     cout << "\nSum is: " << add(3, 3);  // call add function of first namespace

//     cout << "\nADD is: " << add(3.6, 7.8) << endl; // call add function of first namespace

//     //cout<<"\n addition of two is: "<<add(3,4.7f);
//     return 0;
// }

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

using namespace second;
int main()
{
    cout << "\nSum is: " << add(3, 3); // call add function of second namespace

    cout << "\nADD is: " << add(3.6, 7.8) << endl; /* call add function of second
                                                namespace*/

    //cout<<"\n addition of two is: "<<add(3,4.7f);
    return 0;
}

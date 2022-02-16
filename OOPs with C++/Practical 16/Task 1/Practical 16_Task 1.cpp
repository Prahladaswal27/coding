#include<iostream>
using namespace std;

template <typename A, typename B, typename temp>

temp add(A num1, B num2)
{
    temp res = num1 + num2;
    return res;
}

int main()
{
    // Question a part
    cout <<"\nResut of integer addition: "<<add<int, int, int>(10, 35) << endl;
    // Question b part
    cout <<"Result of float addition: "<<add<int, float, double>(20, 40.5f) <<"\n"<<endl;

    return 0;
}

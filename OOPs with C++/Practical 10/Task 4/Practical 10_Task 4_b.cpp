
#include <iostream>
using namespace std;

class overload
{
private:
    int a;

public:
    void get(int n)
    {
        this->a = n;
    }

    void display()
    {
        cout << "\nSum is: " << a << endl;
    }

    overload operator+(overload &var)
    {
        overload obj;
        obj.a = this->a + var.a;
        return obj;
    }
};

int main()
{
    int n1, n2;
    cout << "\nEnter the two numbers: ";
    cin >> n1 >> n2;

    overload o1, o2, sum;
    o1.get(n1);
    o2.get(n2);

    sum = o1 + o2;

    sum.display();

    return 0;
}

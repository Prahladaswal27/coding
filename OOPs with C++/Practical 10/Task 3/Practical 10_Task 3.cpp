
#include <iostream>
using namespace std;

class remainder
{
   private:
    int a, b;

   public:
    remainder(int a, int b)  //parameterized constructor
    {
        this->a = a;  // this pointer use
        this->b = b;  // this pointer use
    }

    int res()
    {
        return (a % b);
    }
};

int main()
{
    int a, b;
    cout << "\nEnter the two no.: ";
    cin >> a >> b;

    remainder r(a, b); // constructor call
    cout << "\nRemainder of two no. is: " << r.res() << endl;
    return 0;
}

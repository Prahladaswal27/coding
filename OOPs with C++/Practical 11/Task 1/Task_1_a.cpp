
#include <iostream>
using namespace std;

class Parent
{
    public:
    void display_Parent()
    {
        cout << "Class Parent Method called " << endl;
    }
};
class Child : protected Parent
{
    public:
    void display_Child()
    {
        cout << "Calling class Parent method from class Child method" << endl;
        display_Parent();
    }
};
int main()
{
    Child obj;
    obj.display_Child();

    return 0;
}

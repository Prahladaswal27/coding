#include <iostream>
using namespace std;

class Parent
{
    public:
    void display_Parent()
    {
        cout << "\nClass Parent method called\n" << endl;
    }
};
class Child : public Parent
{
    public:
    void display_Child()
    {
        cout << "\nCalled class Parent method from class Child method\n" << endl;
        display_Parent();
    }
};

int main()
{
    Child obj;
    obj.display_Parent();

    return 0;
}


#include <iostream>
using namespace std;

class Parent
{
    public:
    void display_Parent()
    {
        cout << "Class Parent method called " << endl;
    }
};
class Child : public Parent
{
    public:
    void display_Child()
    {
        cout << "Called class Parent method from class Child method" << endl;
        display_Parent();
    }
};

int main()
{
    Child obj;
    obj.display_Parent();

    return 0;
}

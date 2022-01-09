
#include <iostream>
using namespace std;

class MarrineAnimals
{
    public:
    void display_MA()
    {
        cout << "I am Marrine Animal" << endl;
    }
};
class Mammals
{
    public:
    void display_M()
    {
        cout << "I am Mammal" << endl;
    }
};

class BlueWhale : public MarrineAnimals, public Mammals
{
    public:
    void display_B()
    {
        cout << "I belong to both categories Mammals as well as Marine Animals" << endl;
    }
};

int main()
{
    Mammals obj1;
    MarrineAnimals obj2;
    BlueWhale obj3;
    obj1.display_M();
    obj2.display_MA();
    obj3.display_B();
    obj3.display_M();
    obj3.display_MA();

    return 0;
}

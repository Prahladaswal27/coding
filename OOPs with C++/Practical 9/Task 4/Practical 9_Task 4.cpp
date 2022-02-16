
#include <iostream>
#include <string>

using namespace std;

class student
{
   private:
    string name;
    int mark, age;

   public:
    void get_data(int i)
    {
        cout << "\nEnter the " << i + 1 << " student name: ";
        cin >> name;
        cout << "Enter the " << i + 1 << " student age: ";
        cin >> age;
        cout << "Enter the " << i + 1 << " student marks: ";
        cin >> mark;
    }

    friend int print_total(student s[]); // friend function declaration
};

int print_total(student s[])
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += s[i].mark;   /*friend function access private members 
                                  using object of class */
                                                                 
    }

    cout << "\nSum of all students marks is: " << sum << endl;
}

int main()
{
    int sum = 0;
    student s[3];

    for (int i = 0; i < 3; i++)
    {
        s[i].get_data(i);
    }

    print_total(s);  //call friend function 

    return 0;
}

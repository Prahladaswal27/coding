
#include <iostream>
#include <string>

using namespace std;
class student
{
private:
    string name;
    int age, year, marks;
    char sec;

public:
    void get_data(int i)
    {
        cout << "\nEnter the " << i + 1 << " student name: ";
        cin >> name;
        cout << "Enter the " << i + 1 << " student section: ";
        cin >> sec;
        cout << "Enter the " << i + 1 << " student age: ";
        cin >> age;
        cout << "Enter the " << i + 1 << " student marks: ";
        cin >> marks;
        cout << "Enter the current year: ";
        cin >> year;
    }

    void print_data(int i)
    {
        cout << "\n   Student details     " << endl;
        cout << "\nStudent " << i + 1 << " name: " << name;
        cout << "\nStudent " << i + 1 << " section: " << sec;
        cout << "\nStudent " << i + 1 << " age: " << age;
        cout << "\nStudent " << i + 1 << " marks: " << marks;
        cout << "\nCurrent year: " << year << endl;
    }
    int total()
    {
        int sum = 0;
        sum += marks;
        return sum;
    }
};

int main()
{
    student s[3]; // array of objects
    int sum = 0;

    for (int i = 0; i < 3; i++) // loop for input data of student
    {
        s[i].get_data(i);
    }
    for (int i = 0; i < 3; i++) // loop for print data of student
    {
        s[i].print_data(i);
        sum += s[i].total();
    }

    cout << "\nTotal of marks is: " << sum << endl; // print sum of all students marks

    return 0;
}

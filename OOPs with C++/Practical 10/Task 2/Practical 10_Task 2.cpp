
#include <iostream>
#include <string>
using namespace std;

class student
{
   private:
    string name;
    int roll_no;
    char sec;

   public:
    void get_data(int i) // function for input students data
    {
        cout << "\nEnter the " << i + 1 << " student name: ";
        cin >> name;
        cout << "Enter the " << i + 1 << " student section: ";
        cin >> sec;
        cout << "Enter the " << i + 1 << " student roll number: ";
        cin >> roll_no;
    }
    void print_data(int i) // function for display students data
    {
        cout << "\n   Student details     " << endl;
        cout << "\nStudent " << i + 1 << " name: " << name;
        cout << "\nStudent " << i + 1 << " section: " << sec;
        cout << "\nStudent " << i + 1 << " roll no: " << roll_no << endl;
    }
};

int main()
{
    int n;
    cout << "\nEnter the total number of student: ";
    cin >> n;

    student obj[n], *s; // array of object
    s = obj;  // pointer to object

    for (int i = 0; i < n; i++)
    {
        (s + i)->get_data(i);
    }

    for (int i = 0; i < n; i++)
    {
        (s + i)->print_data(i);
    }

    return 0;
}


#include <iostream>
#include <string>

using namespace std;

class student
{
    public:
      string add;
      int roll_no;
      long int phn_no;

    void print_data(string s) // function to print details of student
    {
        cout << "\n   Student details     " << endl;

        cout << "\nStudent name: " << s;
        cout << "\nStudent roll no: " << roll_no;
        cout << "\nStudent phone number: " << phn_no;
        cout << "\nStudent address: " << add << endl;
    }
};

int main()
{
    student john, sam; // student class object

    john.roll_no = 2018554;
    john.phn_no = 9123846345;
    john.add = "15 george street, california,USA";

    sam.roll_no = 2018559;
    sam.phn_no = 9875219053;
    sam.add = "17 peter street, california,USA";

    john.print_data("John"); // call print data function of john object
    sam.print_data("Sam");   // call print data function of sam object
}

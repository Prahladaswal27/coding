

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;

    cout << " Enter the name: ";
    getline(cin, name); // read a string or  line from input stream

    cout << "\n Name: " << name; // print whole string from output stream

    return 0;
}

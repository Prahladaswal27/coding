
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1;
    string str2;

    cout << "Enter string 1: ";
    getline(cin, str1);
    cout << endl;

    cout << "Enter string 2: ";
    getline(cin, str2);
    cout << endl;

    int x = str1.compare(str2);
    cout << "Value of x is: " << x;

    if (x == 0)
        cout << "\nBoth string are equal" << endl;
    else if (x == -1)
        cout << "\nString are not equal but their lengths are equal" << endl;
    else if (x > 0)
        cout << "\nString 1 is smaller as compared to String 2" << endl;
    else if (x < 0 && x != -1)
        cout << "\nString 1 is greater as compared to String 2" << endl;

    return 0;
}

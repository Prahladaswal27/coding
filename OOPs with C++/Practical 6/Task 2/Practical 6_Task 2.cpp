
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int i = 0, flag = 1;

    cout << "\nEnter the string: ";
    getline(cin, str);

    string line;

    cout << "\n\nReverse of string is: ";

    string::reverse_iterator rev;
    for (rev = str.rbegin(); rev != str.rend(); rev++)
    {
        cout << *rev;

        line[i] = *rev;
        i++;
    }

    int n = i;
    line[i + 1] = '\0';

    for (i = 0; i < n / 2; i++)
    {

        if (line[i] != str[i])
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        cout << "\n\nString is palindrome" << endl;
    else
        cout << "\n\nString is not palindrome" << endl;

    return 0;
}

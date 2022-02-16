
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "\nUSE OF endl" << endl;
   cout << "GEHU" << endl<< "DEHRADUN" << endl<<"UTTARAKHAND";
      //Insert newline characters and  flushes the stream 


    cout << "\n\nUSE OF setw()\n";
    cout << setw(8) << "DEHRADUN" << endl;  
    // setw sets the width to beused on output operations

    cout << "\nUSE OF setfill()\n";
    cout << setw(12) << setfill('*') << "DEHRADUN" << endl;
    /* setfill is used for specify a different character to fill the unused
       filled width of the value */

    return 0;
}

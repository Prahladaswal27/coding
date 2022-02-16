
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
using namespace std;
int main()
{
    int ch_count = 0, w_count = 0, l_count = 0;
    FILE *fptr;
    char fname[20], ch;

    cout << "\n Enter Source File Name : ";
    gets(fname);

    fptr = fopen(fname, "r");
    if (fptr == NULL)
    {
        cout << "\n Invalid File Name. \n No such File or Directory ";
        exit(0);
    }
    ch = fgetc(fptr);

    while (ch != EOF)
    {
        if (ch != ' ' && ch != '\n')
            ch_count++;

        if (ch == ' ')
            w_count++;

        if (ch == '\n')
        {
            l_count++;
            w_count++;
        }
        ch = fgetc(fptr);
    }
    fclose(fptr);

    cout << " -------------------------------------";
    cout << "\n Total No. of Characters  : " << ch_count;
    cout << "\n Total No. of Words       : " << w_count;
    cout << "\n Total No. of Lines       : " << l_count;

    return 0;
}

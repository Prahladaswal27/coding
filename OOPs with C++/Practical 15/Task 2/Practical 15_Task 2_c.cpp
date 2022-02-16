
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	fstream myfile;
	myfile.open("task_2_c.txt", ios::app);

	if (!myfile)
		cout << "file not created";
	else
		myfile << "  Graphic Era Hill University ";
	myfile << "Welcome to C++";

	myfile.close();

	return 0;
}


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	fstream myfile;
	myfile.open("task_2_b.txt");

	myfile << "Graphic Era Hill University";
	myfile.close();
	return 0;
}

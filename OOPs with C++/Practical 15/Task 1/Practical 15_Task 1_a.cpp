
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ofstream myfile;
	cout<<"\n"<<endl;
	myfile.open("task_1.txt");

	myfile << "Welcome to C plus plus" <<endl;
	myfile.close();

	ifstream readfile;
	string data;

	readfile.open("task_1.txt");
	while (1)
	{
		readfile >> data;

		if (readfile.eof())
		{
			break;
		}
		else
			cout << data << " ";
	}
	readfile.close();

	cout<<"\n"<<endl;
	return 0;
}


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	fstream readfile;
	char data;
	cout<<"\n"<<endl;

	readfile.open("task_2_a.txt");
	while (1)
	{
		readfile >> data;

		if (readfile.eof())
			break;
		else
			cout << data;
	}
	cout <<"\n"<<endl;
	readfile.close();
	return 0;
}

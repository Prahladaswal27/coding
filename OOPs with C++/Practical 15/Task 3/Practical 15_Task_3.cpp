
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	int n = 70;
	cout <<"\n"<<hex << n << endl;
	cout << dec << n << endl;

	char a, b, c;
	stringstream s("  984");
	s >> skipws >> a >> b >> c;
	cout << a << b << c << endl;

	stringstream p("  984");
	p >> noskipws >> a >> b >> c;
	cout << a << b << c << endl;

	stringstream t("  Welcome to graphhic era");
	string line;
	getline(t >> ws, line);
	cout << line <<"\n"<<endl;

	return 0;
}

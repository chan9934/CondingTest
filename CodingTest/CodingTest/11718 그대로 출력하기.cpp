#include <iostream>
#include <string>

using namespace std;

string s;

int main()
{
	while (getline(cin, s))
	{
		cout << s << "\n";
		//cin.ignore();
	}
	return 0;
}
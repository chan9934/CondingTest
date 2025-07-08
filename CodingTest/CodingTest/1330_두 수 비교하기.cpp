#include <iostream>

using namespace std;

int a, b;
int main()
{
	cin >> a >> b;
	a > b ? (cout << ">" << "\n") : (a == b ? (cout << "==" << "\n") : (cout << "<" << "\n"));
		
	return 0;
}
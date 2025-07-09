#include <iostream>

using namespace std;

string s;
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		cout << *s.begin() << *(s.end() - 1) << "\n";
	}
	return 0;
}
#include <iostream>

using namespace std;

int n, ret;
char c;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> c;
		ret += (c - '0');
	}
	cout << ret << "\n";
	return 0;
}
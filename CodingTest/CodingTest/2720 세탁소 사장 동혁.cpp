#include <iostream>

using namespace std;

int n, change;
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> change;
		cout << change / 25 << " ";
		change %= 25;
		cout << change / 10 << " ";
		change %= 10;
		cout << change / 5 << " ";
		change %= 5;
		cout << change<< "\n";
	}
	return 0;
}
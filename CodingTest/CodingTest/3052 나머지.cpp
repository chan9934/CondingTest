#include <iostream>

using namespace std;

int cnt, temp;
int a[43];
int main()
{
	for (int i = 1; i <= 10; ++i)
	{
		cin >> temp;
		if (a[temp % 42] == 0)
		{
			a[temp % 42] = 1;
			++cnt;
		}
	}
	cout << cnt << "\n";
	return 0;
}
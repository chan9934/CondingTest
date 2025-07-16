#include <iostream>

using namespace std;

int a[104][104];

int n, x, y, ret;
int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		for (int j = y; j < y + 10; ++j)
		{
			for (int k = x; k < x + 10; ++k)
			{
				a[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < 104; ++i)
	{
		for (int j = 0; j < 104; ++j)
		{
			if (a[i][j] == 1)
				++ret;
		}
	}
	cout << ret << "\n";
	return 0;
}
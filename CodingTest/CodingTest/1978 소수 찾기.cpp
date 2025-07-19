#include <iostream>

using namespace std;

int n, temp, ret;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		if (!(temp & 1) && temp != 2)
			continue;
		int cnt = 1;
		for (int j = 2; j <= temp; ++j)
		{
			if (temp % j == 0)
			{
				--cnt;
			}
			if (cnt < 0)
				break;

		}
		if (cnt == 0)
			++ret;
	}
	cout << ret << "\n";

	return 0;
}
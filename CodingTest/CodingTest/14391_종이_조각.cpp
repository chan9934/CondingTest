#include <iostream>
#include <bitset>

using namespace std;

int n, m, max_ret;

int a[5][5];
char c;

void go()
{
	for (int s = 0; s < (1 << n * m); ++s)
	{
		int temp = 0;
		int ret = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int k = i * m + j;
				if (s & (1 << k))
				{
					temp *= 10;
					temp += a[i][j];
				}
				else
				{
					ret += temp;
					temp = 0;
				}
			}
			ret += temp;
			temp = 0;
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int k = j * m + i;
				if (!(s & (1 << k)))
				{
					temp *= 10;
					temp += a[j][i];
				}
				else
				{
					ret += temp;
					temp = 0;
				}
			}

			ret += temp;
			temp = 0;
		}
		max_ret = max(max_ret, ret);
	}
	return;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> c;
			a[i][j] = ((int)(c)-'0');
		}
	}
	go();
	cout << max_ret << "\n";
	return 0;
}
#include <iostream>
#include <bitset>

using namespace std;

int n, m, max_ret;

int a[5][5];
char c;

void go(int s[5], int cnt)
{
	if (cnt == n)
	{
		int temp = 0;
		int ret = 0;
		/*cout << " °í°í°í " << "\n";
		for (int i = 0; i < n; ++i)
		{
			cout << bitset<4>(s[i]) << "\n";
		}*/
		for (int i = 0; i < n; ++i)
		{
			for (int j = m - 1; j >= 0; --j)
			{
				if (s[i] & (1 << j))
				{
					temp *= 10;
					temp += a[i][m - j - 1];
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

		//cout << ret << "\n";


		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (!(s[j] & (1 << (m - i - 1))))
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
		//cout << ret << "\n";
		max_ret = max(max_ret, ret);
		return;
	}
	for (int i = 0; i < (1 << m); ++i)
	{
		s[cnt] = i;
		go(s, cnt + 1);
	}
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
	int s[5];
	go(s, 0);
	cout << max_ret << "\n";
	return 0;
}
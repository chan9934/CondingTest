#include <iostream>

using namespace std;

int n, l, ret;
int a[104][104];

void check()
{
	for (int i = 0; i < n; ++i)
	{
		int prev = a[i][0];
		bool success = true;
		int cnt = 1;
		for (int j = 1; j < n; ++j)
		{
			int temp = prev - a[i][j];
			if (temp == 0)
			{
				++cnt;
			}
			else if (abs(temp) == 1)
			{
				if (temp < 0)
				{
					if (!(cnt >= l))
					{
						success = false;
						break;
					}
				}
				else
				{
				}
				cnt = 1;
			}
			else
			{
				success = false;
				break;
			}
		}
		if (success)
			++ret;
	}
}

int main()
{
	cin >> n >> l;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}
	check();
	cout << ret << "\n";
	return 0;
}
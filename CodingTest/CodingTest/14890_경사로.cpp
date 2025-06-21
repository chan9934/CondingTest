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
		int cnt = 0;
		bool slope = false;
		for (int j = 1; j < n; ++j)
		{
			int temp = abs(prev - a[i][j]);
			if (temp == 0)
			{
				if (slope)
				{
					if (cnt == 2)
					{
						slope = false;
						cnt = 0;
					}
					else
					{
						++cnt;
					}
				}
			}
			else if (temp == 1)
			{
				prev = a[i][j];
				if (!slope)
				{
					slope = true;
					++cnt;
				}
				else
				{
					success = false;
					break;
				}
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
#include <iostream>

using namespace std;

int n, l, ret;
int a[104][104];
int b[104][104];

void go(int a[104][104])
{
	for (int i = 0; i < n; ++i)
	{
		int cnt = 1;
		bool success = true;
		for (int j = 0; j < n - 1; ++j)
		{
			int dif = a[i][j + 1] - a[i][j];

			if (dif == 0)
			{
				++cnt;
			}
			else if (dif == 1 && cnt >= l)
			{
				cnt = 1;
			}
			else if (dif == -1)
			{
				for (int k = 0; k < l - 1; ++k)
				{
					++j;
					if (a[i][j + 1] != a[i][j])
					{
						success = false;
						break;
					}
				}
				cnt = 0;
			}
			else
			{
				success = false;
				break;
			}
		}
		if (success)
		{
			++ret;
		}
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
			b[j][i] = a[i][j];
		}
	}

	go(a);
	go(b);
	cout << ret << "\n";
	return 0;
}
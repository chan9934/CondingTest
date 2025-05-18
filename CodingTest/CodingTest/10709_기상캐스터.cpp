#include <iostream>

using namespace std;

int h, w;
char c;

int a[104][104];

int main()
{
	cin >> h >> w;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin >> c;
			if (c == 'c')
			{
				a[i][j] = 0;
			}
			else
			{
				a[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (a[i][j] == 0) {
				int cnt = 1;
				while (a[i][j + 1] == -1)
				{
					a[i][j + 1] = cnt++;
					++j;
				}
			}
			if (j == 0) continue;
			if (a[i][j] == 0)continue;
			int temp = a[i][j - 1];
			if (temp == -1) continue;
			a[i][j]= temp + 1;
		}
	}
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
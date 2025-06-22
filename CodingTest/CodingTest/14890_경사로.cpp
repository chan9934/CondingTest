#include <iostream>

using namespace std;

int n, l, ret;
int a[104][104];
int b[104][104];

void check(int a[104][104])
{
	for (int i = 0; i < n; ++i)
	{
		int cnt = 1;
		bool success = true;
		for (int j = 0; j < n - 1; ++j)
		{
			int temp = a[i][j + 1] - a[i][j];
			if (temp == 0) ++cnt;
			else if (temp == 1 && cnt >= l) cnt = 1;// 오르막길
			else if (temp == -1 && cnt >= 0)cnt = 1 - l;// 내리막길
			else 
			{
				success = false; 
				break;
			}

		}
		if (!success || cnt < 0)continue;
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
			b[j][i] = a[i][j];
		}
	}
	check(a);
	check(b);
	cout << ret << "\n";
	return 0;
}
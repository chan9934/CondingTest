#include <iostream>

using namespace std;

int n, m, i, j, k;
int ret[101];
int main()
{
	cin >> n >> m;
	for (int r = 0; r < m; ++r)
	{
		cin >> i >> j >> k;
		for (int s = i; s <= j; ++s)
		{
			ret[s] = k;
		}
	}
	for (int r = 1; r <= n; ++r)
	{
		cout << ret[i] << " ";
	}
	return 0;
}
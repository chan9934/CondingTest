#include <iostream>

using namespace std;

int n, m, j, ret, p = 1;


int main()
{
	cin >> n >> m >> j;
	int  t = 0;
	for (int i = 0; i < j; ++i)
	{
		cin >> t;
		t;
		int interval = 0;
		if (t < p)
		{
			interval = p - t;
			p -= interval;
		}
		else if (p + m - 1 < t)
		{
			interval = t - p - m + 1;
			p += interval;
		}
		ret += interval;
	}
	cout << ret;
	return 0;
}
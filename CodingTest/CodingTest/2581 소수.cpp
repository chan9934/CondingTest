#include <iostream>
#include <vector>

using namespace std;

int m, n, sum;
vector<int>v;
int main()
{
	cin >> m >> n;
	for (int i = m; i <= n; ++i)
	{
		if (!(i & 1) && i != 2)continue;
		if (i == 1)continue;
		bool success = true;
		for (int j = 3; j < i; j += 2)
		{
			if (i % j == 0)
			{
				success = false;
				break;
			}
		}
		if (success)
		{
			v.push_back(i);
		}
	}
	if (v.empty())
	{
		cout << "-1" << "\n";
	}
	else
	{
		for (const int element : v)
		{
			sum += element;
		}
		cout << sum << "\n" << v[0] << "\n";
	}
	return 0;
}
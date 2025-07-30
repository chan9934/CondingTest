#include <iostream>
#include <map>

using namespace std;

int n, m, num, ret;
map<int, int>mp;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		++mp[num];
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> num;
		++mp[num];
	}
	for (pair<int, int>element : mp)
	{
		if (element.second == 1)
			++ret;
	}
	cout << ret << "\n";
	return 0;
}
#include <iostream>

using namespace std;

pair<int, pair<int, int>> ret;
int temp;
int main()
{
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			cin >> temp;
			if (ret.first <= temp)
			{
				ret.first = temp;
				ret.second = { i, j };
			}
		}
	}
	cout << ret.first << "\n";
	cout << ret.second.first << " " << ret.second.second << "\n";
	return 0;
}
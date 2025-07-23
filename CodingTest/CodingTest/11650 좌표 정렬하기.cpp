#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x, y;
vector<pair<int, int>>coordinate;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		coordinate.push_back({ x, y });
	}
	sort(coordinate.begin(), coordinate.end(),
		[](pair<int, int>first, pair<int, int>second)
		{
			if (first.first < second.first)
			{
				return true;
			}
			else if (first.first == second.first && first.second < second.second)
			{
				return true;
			}
			return false;
		});
	for (const auto element : coordinate)
	{
		cout << element.first << " " << element.second << "\n";
	}
	return 0;
}
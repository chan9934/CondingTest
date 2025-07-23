#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x, y;
vector<pair<int, int>>coordinates;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		coordinates.push_back({ x,y });
	}
	sort(coordinates.begin(), coordinates.end(),
		[](const auto& first, const auto& second)
		{
			if (first.second < second.second)
			{
				return true;
			}
			else if ((first.second == second.second) && (first.first < second.first))
			{
				return true;
			}
			return false;
		});
	for (const auto& element : coordinates)
	{
		cout << element.first << " " << element.second << "\n";
	}
	return 0;
}
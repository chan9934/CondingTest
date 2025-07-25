#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, age;
string name;
vector<pair<int, string>> infos;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> age >> name;
		infos.push_back({ age, name });
	}
	stable_sort(infos.begin(), infos.end(), [](const pair<int, string>& current, const pair<int, string>& next)
		{
			if (current.first < next.first)
				return true;

			return false;
		});
	for (const auto& element : infos)
	{
		cout << element.first << " " << element.second << "\n";
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, m, ret_num;
string str;
map<string, int>list;
vector<string> ret;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		++list[str];
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> str;
		++list[str];
		if (list[str] == 2)
			++ret_num;
	}
	for (const pair<string, int>& element : list)
	{
		if (element.second == 2)
			ret.push_back(element.first);
	}
	cout << ret_num << "\n";
	sort(ret.begin(), ret.end());
	for (const string& element : ret)
	{
		cout << element << "\n";
	}
	return 0;
}
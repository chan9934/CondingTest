#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string>ret;
map<string, bool>s;

int n;
string str, temp;
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> str >> temp;
		s[str] = !s[str];
	}
	for (pair<string, bool> element : s)
	{
		if (element.second)
		{
			ret.push_back(element.first);
		}
	}
	sort(ret.begin(), ret.end(), [](const string& current, const string& next)
		{
			if (current > next)
				return true;
			return false;
		});
	for (const string& element : ret)
	{
		cout << element << "\n";
	}
	return 0;
}
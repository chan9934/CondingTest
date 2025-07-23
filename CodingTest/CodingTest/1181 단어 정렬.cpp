#include <iostream>
#include <vector>
#include <algorithm>
#define prev aaaaaa
using namespace std;
int n;
string str, prev;
vector<string> v;
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(),
		[](const string& first, const string& second)
		{
			if (first.size() < second.size())
			{
				return true;
			}
			else if (first.size() == second.size() && first < second)
			{
				return true;
			}
			return false;
		});
	for (const string& element : v)
	{
		if (element != prev)
			cout << element << "\n";
		
		prev = element;
	}
	return 0;
}
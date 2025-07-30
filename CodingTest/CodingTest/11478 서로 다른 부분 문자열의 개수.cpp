#include <iostream>
#include <unordered_set>

using namespace std;

string s;
unordered_set<string>ret;

int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
	{
		for (int j = s.size() - i; j >= 1; --j)
		{
			ret.insert(s.substr(i, j));
		}
	}
	cout << ret.size() << "\n";
	return 0;
}
#include <iostream>

using namespace std;

int n, ret;
string s;
bool a[26];

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		char flag = ' ';
		for (int j = 0; j < s.size(); ++j)
		{
			if (a[s[j] - 'a'] == false)
			{
				a[s[j] - 'a'] = true;
				flag = s[j];
			}
			else if (flag == s[j])
			{
				continue;
			}
			else
			{
				flag = ' ';
				break;
			}
		}
		if (flag != ' ')
			++ret;
		fill(&a[0], &a[0] + 26, false);
	}
	cout << ret << "\n";
	return 0;
}
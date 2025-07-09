#include <iostream>

using namespace std;

string s;
int a[26];
int main()
{
	fill(&a[0], &a[0] + 26, -1);
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
	{
		if (a[s[i] - 'a'] == -1)
		{
			a[s[i] - 'a'] = i;
		}
	}
	for (int i = 0; i < 26; ++i)
	{
		cout << a[i] << " ";
	}
	return 0;
}
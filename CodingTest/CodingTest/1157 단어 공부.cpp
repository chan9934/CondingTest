#include <iostream>
#include <map>

using namespace std;

string s;
map<char, int>ret;
int max_cnt;
char max_char;

int main()
{
	cin >> s;

	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i] >= 'a')
		++ret[s[i] -'a' + 'A'];
		else
		{
			++ret[s[i]];
		}
	}
	for (auto element : ret)
	{
		if (element.second == max_cnt)
			max_char = '?';
		else if (element.second > max_cnt)
		{
			max_char = element.first;
			max_cnt = element.second;
		}
	}
	cout << max_char << "\n";
	return 0;
}
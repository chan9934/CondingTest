#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int num;
vector<string>cnt_str;
int cnt[26];
string first_chars;

int main()
{
	cin >> num;
	cnt_str.resize(num);
	for (int i = 0; i < num; ++i)
	{
		cin >> cnt_str[i];
		++ cnt[int(cnt_str[i][0])- 'a'];
	}
	for (int i = 0; i < sizeof(cnt) / sizeof(cnt[0]); ++i)
	{
		if (cnt[i] >= 5)
		{
			first_chars += (char('a' + i));
		}
	}
	sort(first_chars.begin(), first_chars.end());
	if (first_chars.empty())
	{
		cout << "PREDAJA";
	}
	else
	{
		for (char chr : first_chars)
		{
			cout << chr;
		}
	}

}
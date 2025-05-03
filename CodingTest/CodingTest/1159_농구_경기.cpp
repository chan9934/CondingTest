#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int num;
vector<string>cnt_str;
map<char, int>first_names;
vector<char>first_chars;

int main()
{
	cin >> num;
	cnt_str.resize(num);
	for (int i = 0; i < num; ++i)
	{
		cin >> cnt_str[i];
		first_names[cnt_str[i][0]] += 1;
	}
	for (auto first_name : first_names)
	{
		if (first_name.second >= 5)
		{
			first_chars.emplace_back(first_name.first);
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
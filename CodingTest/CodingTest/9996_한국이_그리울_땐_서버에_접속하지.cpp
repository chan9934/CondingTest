#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define YES "DA"
#define NO "NE"

int num;
string pattern, left_str, right_str;
vector<string>return_strs;

int main()
{
	cin >> num >> pattern;
	size_t start_pos;
	start_pos = pattern.find('*');
	left_str = pattern.substr(0, start_pos);
	right_str = pattern.substr(start_pos + 1);

	/*string str;
	cin >> str;
	cout << right_str << endl;
	cout << str.find_last_of(right_str, size(right_str));*/
	for (int i = 0; i < num; ++i)
	{
		string str;
		cin >> str;
		string temp_right_str = str;
		reverse(temp_right_str.begin(), temp_right_str.end());
		if (size(str) < size(left_str) + size(right_str))
		{
			return_strs.emplace_back(NO);
		}
		else if (left_str == str.substr(0, size(left_str)) && right_str == str.substr(size(str) - size(right_str)))
		{
			return_strs.emplace_back(YES);
		}
		else
		{
			return_strs.emplace_back(NO);
		}
	}
	for (string return_str : return_strs)
	{
		cout << return_str << endl;
	}
	return 0;
}
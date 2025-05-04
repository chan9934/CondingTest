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
	reverse(right_str.begin(), right_str.end());

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
		auto find_left = str.find(left_str);
		auto find_right = temp_right_str.find(right_str);
		if (size(str) < size(left_str) + size(right_str))
		{
			return_strs.emplace_back(NO);
		}
		else if (find_left == 0 && find_right == 0)
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
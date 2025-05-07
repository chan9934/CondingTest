#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

#define FAIL "I'm Sorry Hansoo"
#define INDEX_NONE -1
using namespace std;

string name;
int arr[26];
set<int> set_odd_index;

int main()
{
	cin >> name;

	for (char element : name)
	{
		int index = (int)element - (int)('A');
		int value = ++arr[index];
		if (value % 2 != 0)
		{
			set_odd_index.insert(index);
		}
		else
		{
			set_odd_index.erase(index);
		}
	}
	int odd_index = INDEX_NONE;
	if ((int)set_odd_index.size() > 1)
	{
		cout << FAIL;
		return 0;
	}
	else if (set_odd_index.size() == 1)
	{
		odd_index = *set_odd_index.begin();
	}

	string left_str, right_str, ret;
	for (int i = 0; i < 26; ++i)
	{
		int number = arr[i];
		if (number == 0) continue;
		char element = (char)i + 'A';
		for (int i = 0; i < number / 2; ++i)
		{
			left_str += element;
		}
	}
	ret = right_str = left_str;
	if (odd_index != INDEX_NONE)
	{
		char element = (char)odd_index + 'A';
		ret += element;
	}
	reverse(right_str.begin(), right_str.end());
	ret += right_str;
	cout << ret << endl;
	return 0;
}
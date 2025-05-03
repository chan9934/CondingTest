#include <iostream>
#include <algorithm>

using namespace std;

string str, left_str, right_str;

int main()
{
	cin >> str;
	int size = str.size();
	if ((size % 2) == 0)
	{
		left_str = str.substr(0, size / 2);
		right_str = str.substr(size / 2);
	}
	else
	{
		left_str = str.substr(0, size / 2 + 1);
		right_str = str.substr(size / 2);
	}
	reverse(right_str.begin(), right_str.end());
	cout << (left_str == right_str ? 1 : 0) << endl;
	return 0;
}
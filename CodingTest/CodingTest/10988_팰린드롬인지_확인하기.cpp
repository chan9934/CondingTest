#include <iostream>
#include <algorithm>

using namespace std;

string str, temp_str;

int main()
{
	cin >> str;
	temp_str = str;

	reverse(temp_str.begin(), temp_str.end());
	cout << (str == temp_str ? 1 : 0) << endl;
	return 0;
}
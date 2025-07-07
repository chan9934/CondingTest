#include <iostream>

using namespace std;

int n, ret;
string s;

int main()
{
	cin >> n >> s;

	cout << n * (s[2] - '0') << "\n";
	ret += n * (s[2] - '0');
	cout << n * (s[1] - '0') << "\n";
	ret += n * (s[1] - '0') * 10;
	cout << n * (s[0] - '0') << "\n";
	ret += n * (s[0] - '0') * 100;
	cout << ret << "\n";
	return 0;
}
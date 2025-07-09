#include <iostream>

using namespace std;

int ret;
string s;
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] <= 'C') ret += 3;
		else if (s[i] <= 'F') ret += 4;
		else if (s[i] <= 'I') ret += 5;
		else if (s[i] <= 'L') ret += 6;
		else if (s[i] <= 'O') ret += 7;
		else if (s[i] <= 'S') ret += 8;
		else if (s[i] <= 'V') ret += 9;
		else if (s[i] <= 'Z') ret += 10;
	}
	cout << ret << "\n";
	return 0;
}
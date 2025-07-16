#include <iostream>

using namespace std;

int n, b;
string ret;

int main()
{
	cin >> n >> b;

	while (n > 0)
	{
		int digit = n % b;
		n /= b;
		char c = '\n';
		if (digit < 10)
			c = digit + '0';
		else
			c = digit - 10 + 'A';

		ret += c;
	}
	reverse(ret.begin(), ret.end());
	cout << ret << "\n";
	return 0;
}
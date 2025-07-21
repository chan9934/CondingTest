#include <iostream>

using namespace std;

long long n, ret;

int main()
{
	cin >> n;
	for (int i = 1; i <= n - 1; ++i)
	{
		ret += (n - (i + 1) + 1);
	}
	cout << ret << "\n" << 2 << "\n";
	return 0;
}
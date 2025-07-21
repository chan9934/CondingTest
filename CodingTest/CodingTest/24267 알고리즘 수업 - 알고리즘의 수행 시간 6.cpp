#include <iostream>

using namespace std;

long long n, ret;
int i, j, k;
int main()
{
	cin >> n;
	if (n < 3)
		ret = 0;
	else if (n == 3)
		ret = 1;
	else
	{
		ret = n* (n - 1)* (n - 2) / 6;
	}
	cout << ret << "\n" << "3\n";
	return 0;
}
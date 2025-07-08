#include <iostream>

using namespace std;

int n, m, r;

int main()
{
	cin >> n >> m >> r;
	if ((n == m) && (n == r))
	{
		cout << 10000 + n * 1000;
	}
	else if(n == m || n == r)
	{
		cout << 1000 + n * 100;
	}
	else if (m == r)
	{
		cout << 1000 + m * 100;
	}
	else
	{
		cout << max(max(n, m), r) * 100;
	}
	return 0;
}
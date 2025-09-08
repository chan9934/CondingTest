#include <iostream>

using namespace std;

int n, m;

bool isPrime(int num)
{
	if (num < 2) return false;
	if (num == 2)return true;
	if (!(num % 2))return false;
	for (int i = 3; i * i <= num; i+=2)
	{
		if (!(num % i)) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = n; i <= m; ++i)
	{
		if (isPrime(i))
			cout << i << "\n";
	}
	return 0;
}
#include <iostream>

using namespace std;

int n, ret;

bool isPrime(int num)
{
	if (num < 2)return false;
	if (num == 2) return true;
	if (num % 2 == 0)return false;
	for (int i = 3; i * i <= num; ++i)
	{
		if (num % i == 0) return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	while(cin >> n)
	{
		if (n == 0) break;
		ret = 0;
		for (int i = n + 1; i <= 2 * n; ++i)
		{
			if (isPrime(i))
				++ret;
		}
		cout << ret << "\n";
	}
	return 0;
}
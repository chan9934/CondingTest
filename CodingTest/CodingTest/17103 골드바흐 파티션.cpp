#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n, t;

const int MAX_N = 1000000;
bool isPrime[MAX_N + 1];
void sieve()
{
	fill(isPrime, isPrime + MAX_N + 1, true);
	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i * i <= MAX_N; ++i)
	{
		if(isPrime[i])
		{
			for (int j = i * i ; j <= MAX_N; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	sieve();
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int cnt = 0;
		cin >> n;
		for (int j = 2; j <= n / 2; j ++)
		{
			if (isPrime[j] && isPrime[n - j])
			{
				++cnt;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
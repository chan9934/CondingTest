#include<iostream>
#include<bitset>

using namespace std;

int n, ret;
int a[24];
string s;
void go(int here)
{
	if (here == n)
	{
		int sum = 0;
		for (int i = 1; i < (1<<n); i *= 2)
		{
			int cnt = 0;
			for (int j = 0; j < n; ++j)
			{
				if (a[j] & i) ++cnt;
			}
			sum += min(cnt, n - cnt);
		}
		int temp = ret;
		ret = min(ret, sum);
		return;
	}
	go(here + 1);
	a[here] = ~a[here];
	go(here + 1);
}
int main()
{
	cin >> n;
	ret = 400;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		int value = 1;
		for (int j = 0; j < n; ++j)
		{
			if (s[j] == 'T') a[i] |= value;
			value *= 2;
		}
	}
	go(0);
	cout << ret;
	return 0;
}
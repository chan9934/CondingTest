#include <iostream>
using namespace std;
int n, ret, a;
int p[100004];
int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	cin >> n;
	ret = 1000000000;
	cin >> p[0];
	for (int i = 1; i < n; ++i)
	{
		cin >> p[i];
		a = gcd(a, p[i] - p[i - 1]);
	}
	
	cout << (p[n - 1] / a) - (p[0] / a) + 1 - n << "\n";
	return 0;
}
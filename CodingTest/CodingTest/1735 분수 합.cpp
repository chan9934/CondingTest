#include <iostream>

using namespace std;
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

int a1, b1, a2, b2, a3, b3;
int main()
{
	cin >> a1 >> b1 >> a2 >> b2;
	a3 = a2 * b1 + a1 * b2;
	b3 = b1 * b2;
	int n = gcd(a3, b3);
	cout << a3/n << " " << b3 / n << "\n";
	return 0;
}
#include <iostream>

using namespace std;

int n;

int main()
{
	cin >> n;
	int temp = n;
	for (int i = 2; i <= temp; ++i)
	{
		if (i > n)break;
		if (n % i == 0)
		{
			n /= i;
			cout << i << "\n";
			--i;
		}
	}
	return 0;
}
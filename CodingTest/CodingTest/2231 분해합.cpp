#include <iostream>

using namespace std;

int n, ret;
int getDigitSum(int num)
{
	int sum = 0;
	while (num > 0)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
int main()
{
	cin >> n;
	for (int i = max(1, n - 54); i <= n; ++i)
	{
		if (i + getDigitSum(i) == n)
		{
			ret = i;
			break;
		}
	}
	cout << ret << "\n";
	return 0;
}
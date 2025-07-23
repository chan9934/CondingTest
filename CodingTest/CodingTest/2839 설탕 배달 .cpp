#include <iostream>

using namespace std;

int n, ret;
bool success;
int main()
{
	ret = 5000 / 3;

	cin >> n;
	for (int i = 0; i <= n / 3; ++i)
	{
		for (int j = 0; j <= n / 5; ++j)
		{
			if ((3 * i) + (5 * j) == n)
			{
				ret = min(ret, i + j);
				success = true;
			}
		}
	}
	if (success)
		cout << ret << "\n";
	else
		cout << "-1" << "\n";
	return 0;
}
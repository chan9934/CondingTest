#include <iostream>

using namespace std;

int a, b, t, ret;

int main()
{
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> a >> b;
		int target = a;
		while (target % b != 0)
		{
			target += a;
		}
		ret = target;
		target = b;
		while (target % a != 0)
		{
			target += b;
		}
		cout << min(ret, target) << "\n";
	}
	return 0;
}
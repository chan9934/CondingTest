#include <iostream>

using namespace std;

int a, b;
long long ret;

int main()
{
	cin >> a >> b;
	long long target = a;
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
	ret = min(ret, target);
	cout << ret << "\n";
	return 0;
}
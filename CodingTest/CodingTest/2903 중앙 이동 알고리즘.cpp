#include <iostream>

using namespace std;

int n, ret;
int main()
{
	cin >> n;

	ret = 1;
	for (int i = 0; i < n; ++i)
	{
		ret *= 2;
	}
	ret += 1;
	ret *= ret;
	cout << ret;
	return 0;
}
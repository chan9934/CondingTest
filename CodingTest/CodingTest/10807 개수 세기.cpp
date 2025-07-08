#include <iostream>
using namespace std;

int n, a[101], v, ret;
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cin >> v;

	for (int i = 0; i < n; ++i)
	{
		if (a[i] == v)
			++ret;
	}
	cout << ret << "\n";
	return 0;
}
#include <iostream>

using namespace std;

int n, temp, min_ret, max_ret;
int main()
{
	min_ret = 1000000;
	max_ret = -1000000;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		min_ret = min(min_ret, temp);
		max_ret = max(max_ret, temp);
	}
	cout << min_ret << " " << max_ret << "\n";
	return 0;
}
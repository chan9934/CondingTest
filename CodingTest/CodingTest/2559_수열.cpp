#include <iostream>
#include <vector>

using namespace std;

int n, r, ret_max;
int sum_v[100004];

int main()
{
	cin >> n >> r;
	ret_max = -(100 * r) - 4;
	for (int i = 1; i <= n; ++i)
	{
		int num;
		cin >> num;
		sum_v[i] = sum_v[i - 1] + num;
	}
	for (int i = r; i <= n; ++i)
	{
		ret_max = max(ret_max, sum_v[i] - sum_v[i - r]);
	}
	cout << ret_max;
	return 0;
}
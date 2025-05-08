#include <iostream>
#include <vector>
using namespace std;

int n, ret_cnt;
long long m;
vector<int> v;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int number;
		cin >> number;
		if (number >= m)
			continue;
		v.emplace_back(number);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (v[i] + v[j] == m)
				++ret_cnt;
		}
	}
	cout << ret_cnt;
	return 0;
}
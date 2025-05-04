#include <iostream>
#include <vector>

using namespace std;

int n, r, ret_max;
vector<int>v;
vector<int>sum_v;

int main()
{
	cin >> n >> r;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		v.emplace_back(num);
		if (v.size() >= r)
		{
			if (sum_v.empty())
			{
				int sum = 0;
				for (int j = 0; j < r; ++j)
				{
					sum += v[j];
				}
				sum_v.emplace_back(sum);
				ret_max = sum;
				continue;
			}
			else
			{
				sum_v.emplace_back(sum_v[i - r] - v[i - r] +v[i]);
			}
			ret_max = max(ret_max, *(sum_v.end() - 1));
		}
		
	}
	cout << ret_max;
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int n, ret;
int mp, mf, ms, mv;
int a[20][10];

vector<int> v_ret;

int main()
{
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
	}
	int max_n = 10000;
	ret = max_n;
	for (int i = 0; i < (1 << n); ++i)
	{
		vector<int>v;
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				v.push_back(j);
			}
		}

		int temp_p = 0, temp_f = 0, temp_s = 0, temp_v = 0, temp_t = 0;
		for (auto element : v)
		{
			temp_p += a[element][0];
			temp_f += a[element][1];
			temp_s += a[element][2];
			temp_v += a[element][3];
			temp_t += a[element][4];
		}
		if (temp_p >= mp && temp_f >= mf && temp_s >= ms && temp_v >= mv)
		{
			if (ret >= temp_t)
			{
				if (ret == temp_t)
				{
					if (v < v_ret)
					{
						v_ret = v;
					}
				}
				else
				{
					v_ret = v;
				}
				ret = min(ret, temp_t);
			}
		}
	}
	if (ret == max_n)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << ret << "\n";
		for (auto element : v_ret)
		{
			cout << element + 1 << " ";
		}
	}
	return 0;
}
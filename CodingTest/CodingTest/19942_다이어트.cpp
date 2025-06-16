#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, ret;
int mp, mf, ms, mv;
int b, c, d, e, f;

struct A {
	int mp, mf, ms, mv, cost;
} a[16];

map<int, vector<vector<int>>> ret_v;

int main()
{
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;
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

		b = c = d = e = f = 0;
		for (auto element : v)
		{
			b += a[element].mp;
			c += a[element].mf;
			d += a[element].ms;
			e += a[element].mv;
			f += a[element].cost;
		}
		if (b >= mp && c >= mf && d >= ms && e >= mv)
		{
			if (ret >= f)
			{
				ret = min(ret, f);
				ret_v[ret].push_back(v);
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
		vector < vector<int>> v = ret_v[ret];
		sort(v.begin(), v.end());
		for (auto element : *v.begin())
		{
			cout << element + 1 << " ";
		}
	}
	return 0;
}
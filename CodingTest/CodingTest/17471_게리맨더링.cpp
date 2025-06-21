#include<iostream>
#include<vector>

using namespace std;

const int max_ret = 1000;
int n, m, ret = max_ret;
vector<int>v[11];
int a[11];
int comp[11];
int visited;

pair<int, int> dfs(int here, int index)
{
	visited |= (1 << here);
	pair<int, int> ret = { 1, a[here] };
	for (int next : v[here])
	{
		if (comp[next] != index)continue;
		if (visited & (1 << next)) continue;
		pair<int, int> temp = dfs(next, index);
		ret.first += temp.first;
		ret.second += temp.second;
	}
	return ret;
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		a[i] = temp;
	}

	for (int i = 1; i <= n; ++i)
	{
		cin >> m;
		int temp = 0;
		for (int j = 0; j < m; ++j)
		{
			cin >> temp;
			v[i].push_back(temp);
		}
	}

	for (int i = 1; i < (1 << n); ++i)
	{
		visited = 0;
		fill(&comp[0], &comp[0] + 11, 0);
		int comp_0 = 0;
		int comp_1 = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (i & (1 << (j-1)))
			{
				comp[j] = 1; comp_1 = j;
			}
			else
			{
				comp_0 = j;
			}
		}
		if (comp_1 == 0 || comp_0 == 0)continue;

		pair<int, int>first = dfs(comp_1, 1);
		pair<int, int>second = dfs(comp_0, 0);
		if (first.first + second.first != n)continue;

		ret = min(ret, abs(first.second - second.second));
	}
	if (ret == max_ret)cout << -1 << "\n";
	else cout << ret << "\n";
	return 0;
}
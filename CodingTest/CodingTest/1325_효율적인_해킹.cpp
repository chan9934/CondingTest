#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n, m;
int a, b;
vector<int>adj [10004] ;
map<int, int> dfs_values;
vector<int>ret;
int max_number;

int dfs(int here)
{
	if (dfs_values.end() != dfs_values.find(here))
		return dfs_values[here];
	int ret = 0;
	int number = 1;
	for (int there : adj[here])
	{
		if (!adj[there].empty())
		{
			number += dfs(there);
		}
		ret = max(ret, number);
	}
	dfs_values[here] = ret;

	return ret;
}
int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
	{
		int temp = dfs(i);
		if (max_number < temp)
		{
			max_number = temp;
			ret.clear();
			ret.push_back(i);
		}
		else if(max_number == temp)
		{
			ret.push_back(i);
		}
	}
	sort(ret.begin(), ret.end());
	for (int element : ret)
	{
		cout << element << " ";
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n, m;
int a, b;
vector<int>adj[10004];
int visited[10004];
vector<int>ret;
int max_number;

int dfs(int here)
{
	visited[here] = 1;
	int number = 1;
	for (int there : adj[here])
	{
		if (visited[there] == 1)
			continue;
		number += dfs(there);
	}
	return number;
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
		fill(&visited[0], &visited[0] + 10004, 0);
		int temp = dfs(i);
		if (max_number < temp)
		{
			max_number = temp;
			ret.clear();
			ret.push_back(i);
		}
		else if (max_number == temp)
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
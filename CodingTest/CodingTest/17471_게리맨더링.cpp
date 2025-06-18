#include<iostream>
#include<vector>

using namespace std;

int n, m, ret;
int a[14];
vector<int>adj[14];
int visited[14];
int component[14];
pair<int, int>dfs(int here, int value)
{
	visited[here] = 1;
	pair<int, int> p = { 1, a[here]};
	for (auto next : adj[here])
	{
		if (visited[next])continue;
		if (component[next] != value)continue;

		pair<int, int> _temp = dfs(next, value);
		p.first += _temp.first;
		p.second += _temp.second;
	}
	return p;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> m;
		for (int j = 0; j < m; ++j)
		{
			int temp = 0;
			cin >> temp;
			adj[i].push_back(temp -1);
		}
	}
	ret = 1000;
	for (int i = 1; i < (1 << n) - 1; ++i)
	{
		fill(&component[0], &component[0] + 14, 0);
		fill(&visited[0], &visited[0] + 14, 0);

		int idx1 = -1;
		int idx2 = -1;
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))component[j] = 1, idx1 = j;
			else idx2 = j;
		}
		if (idx1 == -1 || idx2 == -1)continue;
		pair<int, int>comp1 = dfs(idx1, 1);
		pair<int, int>comp2 = dfs(idx2, 0);
		if (comp1.first + comp2.first == n) ret = min(ret, abs(comp1.second - comp2.second));
	}
	cout << (ret == 1000 ? -1:ret) << "\n";
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int t, n, m, a, b, cnt;
int visited[1004];
vector<int>adj[1004];

void dfs(int here)
{
	visited[here] = 1;

	for (int next : adj[here])
	{
		if (!visited[next])
		{
			dfs(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> n;
		cin >> m;
		cnt = 0;
		for (int i = 0; i < 1004; ++i)adj[i].clear();
		fill(visited, visited + 1004, 0);
		for (int j = 0; j < m; ++j)
		{
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for (int j = 1; j <= n; ++j)
		{
			if (!visited[j])
			{
				dfs(j);
				++cnt;
			}
		}
		if (cnt > 1 || m != n - 1) cout << "graph" << "\n";
		else cout << "tree" << "\n";
	}
}
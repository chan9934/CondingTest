#include <iostream>
#include <set>

using namespace std;

int t, n, m, n_f, n_t;
int visited[1004];
bool ret;
set<int>v[1004];
void dfs(int from)
{
	visited[from] = 1;

	for (int next : v[from])
	{
		if (!visited[next])
			dfs(next);
	}
}
int main()
{
	cin >> t;

	for (int i = 0; i < t; ++i)
	{

		for (int j = 1; j <= n; ++j) {
			v[j].clear();
		}
		fill(&visited[0], &visited[0] + 110, 0);
		ret = true;
		cin >> n >> m;
		int cnt = 0;
		if(m != n-1)
		{
			ret = false;
		}

		for (int j = 0; j < m; ++j)
		{
			cin >> n_f >> n_t;
			if(v[n_f].end() == v[n_f].find(n_t))
			{
				v[n_f].insert(n_t);
				v[n_t].insert(n_f);
			}
			else
			{
				ret = false;
				continue;
			}
		}
		if (!ret)
		{
			cout << "graph" << "\n";
			continue;
		}
		for (int j = 1; j <= n; ++j)
		{
			if (!visited[j])
			{
				++cnt;
				dfs(j);
			}
		}
		if (cnt > 1)
			ret = false;
		if (ret)
			cout << "tree" << "\n";
		else
		{
			cout << "graph" << "\n";
		}
	}
}

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int t, n, m, k, ret;
int y, x;
const int v = 54;
vector<int>adj[v];
bool visited[v][v];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void go(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= 50 || nx >= 50)continue;
		if (visited[ny][nx] == true)continue;
		for (int there : adj[ny])
		{
			if (there != nx) continue;

			go(ny, nx);
		}
	}
}
int main()
{
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> m >> n >> k;
		for (int j = 0; j < k; ++j)
		{
			cin >> x >> y;
			adj[y].push_back(x);
		}
		for (int j = 0; j < v; ++j)
		{
			for (int there : adj[j])
			{
				if (visited[j][there] == true)continue;
				go(j, there);
				++ret;
			}
		}
		cout << ret << "\n";
		memset(visited, 0, sizeof(visited));
		memset(adj, 0, sizeof(adj));

		ret = 0;
	}
	return 0;
}
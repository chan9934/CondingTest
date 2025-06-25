#include <iostream>

using namespace std;

int a[51][51];
int visited[51][51];
int component[2504];
int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };
int m, n, ret_1, ret_2, ret_3;

int dfs(int y, int x, int cnt)
{
	visited[y][x] = cnt;

	int ret = 1;
	for (int i = 0; i < 4; ++i)
	{
		if (a[y][x] & (1 << i))
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx])continue;
			ret += dfs(ny, nx, cnt);
		}
	}
	return ret;
}

int main()
{
	cin >> m >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (visited[i][j]) continue;
			++ret_2;
			int cnt = dfs(i, j, ret_2);
			component[ret_2] = cnt;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (i + 1 < n)
			{
				int a = visited[i][j];
				int b = visited[i + 1][j];
				if (a != b)
				{
					ret_3 = max(ret_3, component[a] + component[b]);
				}
			}
			if (j + 1 < m)
			{
				int a = visited[i][j];
				int b = visited[i][j + 1];
				if (a != b)
				{
					ret_3 = max(ret_3, component[a] + component[b]);
				}
			}
		}
	}
	cout << ret_1 << "\n" << ret_2 << "\n" << ret_3 << "\n";
	return 0;
}
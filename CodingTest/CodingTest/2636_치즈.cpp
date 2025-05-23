#include <iostream>

using namespace std;

int n, m, cnt, ret;
int a[104][104];
int visited[104][104];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
bool melt_check(int y, int x)
{
	bool melt = false;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (a[ny][nx] != 1)
		{
			melt = true;
			break;
		}
	}
	return melt;
}
void dfs(int y, int x)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (visited[ny][nx] == 1)continue;
		if (a[ny][nx] == 0)
		{
			dfs(ny, nx);
		}
		else
		{
			visited[ny][nx] = 1;
		}
	}

}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
				++ret;
		}
	}
	int prev = ret;
	while (true)
	{
		if (ret == 0)
		{
			cout << cnt << "\n";
			cout << prev << "\n";
			break;
		}
		prev = ret;
		dfs(0, 0);

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (visited[i][j] == 1)
				{
					visited[i][j] = 0;
					if (a[i][j] == 1)
					{
						--ret;
						a[i][j] = 0;
					}

				}
			}
		}
		
		++cnt;
	}
}
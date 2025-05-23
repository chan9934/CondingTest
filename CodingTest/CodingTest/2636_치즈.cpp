#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt, cnt2;
int a[104][104];
int visited[104][104];
vector < pair<int, int>>v;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
void dfs(int y, int x)
{
	visited[y][x] = 1;
	if (a[y][x] == 1)
	{
		v.push_back({ y,x });
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (visited[ny][nx] == 1)continue;
		dfs(ny, nx);
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
		}
	}
	while (true)
	{
		fill(&visited[0][0], &visited[0][0] + (104 * 104), 0);
		v.clear();
		dfs(0, 0);

		cnt2 = v.size();
		if (cnt2 == 0)
			break;

		for (pair<int, int> b : v) {
			a[b.first][b.second] = 0;
		}
		bool flag = true;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (a[i][j] == 1)
					flag = false;
			}
		}

		++cnt;
		if (flag)
			break;
	}
	cout << cnt << '\n' << cnt2 << '\n';
}
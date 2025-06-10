#include <iostream>

using namespace std;

int r, c, ret = 1;

const int max_n = 21;
char a[max_n][max_n];
char c_visited[26];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
void dfs(int y, int x, int depth)
{
	ret = max(ret, depth);
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c)continue;
		if (c_visited[a[ny][nx] - 'A'] == 0)
		{
			c_visited[a[ny][nx] - 'A'] = 1;
			dfs(ny, nx, depth + 1);
			c_visited[a[ny][nx] - 'A'] = 0;
		}
	}
}
int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> a[i][j];
		}
	}

	c_visited[a[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	cout << ret;
}
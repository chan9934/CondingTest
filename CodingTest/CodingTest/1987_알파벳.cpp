#include <iostream>

using namespace std;

const int max_n = 21;
char a[max_n][max_n];
bool visited[26];
int r, c, ret;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x, int& cnt)
{
	ret = max(ret, cnt);
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c)continue;
		if (visited[a[ny][nx] - 'A'] == 1)continue;


		visited[a[ny][nx] - 'A'] = 1;
		++cnt;
		dfs(ny, nx, cnt);
		visited[a[ny][nx] - 'A'] = 0;
		--cnt;
	}
}
int main()
{
	cin >> r >> c;
	ret = 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> a[i][j];
		}
	}
	visited[a[0][0] - 'A'] = 1;
	int cnt = 1;
	dfs(0, 0, cnt);
	cout << ret;
}
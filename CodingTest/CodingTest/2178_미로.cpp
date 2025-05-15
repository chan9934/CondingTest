#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char adj[104][104];
int visited[104][104];
int n, m;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void go(int y, int x)
{
	visited[y][x] = 1;
	queue <tuple< int, int >> q;
	q.push(tie(y, x));

	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 1 || nx < 1 || ny > n || nx > m)continue;
			if (adj[ny][nx] == '0')continue;
			if (visited[ny][nx] != 0) continue;

			visited[ny][nx] = visited[y][x] + 1;
			if (ny == n && nx == m)return;

			q.push(tie(ny, nx));
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// row column ÁöÁ¤
	cin >> n >> m;

	// ¸Ê ¼ÂÆÃ
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> adj[i][j];
		}
	}
	go(1, 1);
	cout << visited[n][m];

	return 0;
}
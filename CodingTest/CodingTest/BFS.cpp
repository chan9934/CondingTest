#include <iostream>
#include <queue>

using namespace std;

int n, m, ret;
int start_x, start_y, end_x, end_y;
int a[104][104];
int visited[104][104];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
void bfs()
{
	queue<pair<int, int>>q;
	q.push(make_pair(start_y, start_x));
	visited[start_y][start_x] = 1;
	while (q.size())
	{
		pair<int, int> u = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = u.first + dy[i];
			int nx = u.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (a[ny][nx] == 0)continue;
			if (visited[ny][nx] == 0)
			{
				visited[ny][nx] = visited[u.first][u.second] + 1;
				if (ny == end_y && nx == end_x)
					return;
				q.push(make_pair(ny, nx));
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	cin >> start_y >> start_x;
	cin >> end_y >> end_x;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
		}
	}
	bfs();
	cout << visited[end_y][end_x];
	return 0;
}
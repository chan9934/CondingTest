#include <iostream>
#include <queue>

using namespace std;

#define y1 actual_y1
int n, m;
int x1, y1, x2, y2;
char a[304][304];
int visited[304][304];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void bfs()
{
	visited[x1 - 1][y1 - 1] = 1;
	queue<pair<int, int>>q_0;
	queue<pair<int, int>>q_1;
	q_0.push({ x1 - 1, y1 - 1 });
	while (q_0.size() || q_1.size())
	{
		while (q_0.size())
		{
			pair<int, int> here = q_0.front();
			q_0.pop();

			for (int i = 0; i < 4; ++i)
			{
				int ny = here.first + dy[i];
				int nx = here.second + dx[i];

				if (ny < 0 || nx < 0 || ny> 300 || nx>300)continue;
				if (visited[ny][nx]) continue;

				if (a[ny][nx] == '1')
				{
					q_1.push({ ny, nx });
					visited[ny][nx] = visited[here.first][here.second] + 1;
				}
				else if (a[ny][nx] == '0')
				{
					q_0.push({ ny, nx });
					visited[ny][nx] = visited[here.first][here.second];
				}
			}
		}
		while (q_1.size())
		{
			pair<int, int> here = q_1.front();
			q_1.pop();

			for (int i = 0; i < 4; ++i)
			{
				int ny = here.first + dy[i];
				int nx = here.second + dx[i];

				if (ny < 0 || nx < 0 || ny> 300 || nx>300)continue;

				if (visited[ny][nx]) continue;

				if (a[ny][nx] == '1')
				{
					q_1.push({ ny, nx });
					visited[ny][nx] = visited[here.first][here.second] + 1;
				}
				else if (a[ny][nx] == '0')
				{
					q_0.push({ ny, nx });
					visited[ny][nx] = visited[here.first][here.second];
				}
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	cin >> x1 >> y1 >> x2 >> y2;
	if (x1 == x2 && y1 == y2)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
		}
	}
	bfs();
	cout << visited[x2 - 1][y2 - 1];
	return 0;
}
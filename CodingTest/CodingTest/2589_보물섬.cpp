#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m, ret;

char arr[54][54];
int visited[54][54];

int dy[] = { -1, 0, +1, 0 };
int dx[] = { 0, 1, 0, -1 };

int bfs(int y, int x)
{
	int d = 1;
	visited[y][x] = 0;

	queue<pair<int, int>> q;
	q.push({ y, x });

	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (visited[ny][nx] != -1)continue;
			if (arr[ny][nx] == 'L')
			{
				q.push({ ny, nx });
				visited[ny][nx] = visited[y][x] + 1;
				d = visited[ny][nx];
			}
		}
	}
	return d;
	
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (arr[i][j] == 'L')
			{
				fill(&visited[0][0], &visited[0][0] + 54 * 54, -1);
				ret = max(ret, bfs(i, j));
			}
		}
	}
	cout << ret;
}
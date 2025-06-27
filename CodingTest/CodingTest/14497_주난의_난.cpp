	#include <iostream>
	#include <queue>

	using namespace std;
	#define y1 y1_real

	int n, m;
	const int max_n = 300;
	char a[max_n + 4][max_n + 4];
	int visited[max_n + 4][max_n + 4];
	int x1, y1, x2, y2;
	int dy[] = { -1, 0, 1, 0 };
	int dx[] = { 0, 1, 0, -1 };

	void bfs(int y, int x)
	{
		queue<int>q;
		queue<int>temp;
		q.push(1000 * y + x);
		visited[y][x] = 1;
		while (q.size())
		{
			while (q.size())
			{
				y = q.front() / 1000;
				x = q.front() % 1000;
				q.pop();

				for (int i = 0; i < 4; ++i)
				{
					int ny = y + dy[i];
					int nx = x + dx[i];

					if (ny < 0 || nx < 0 || ny > n || nx > m)continue;
					if (visited[ny][nx])continue;
					if (a[ny][nx] == '0')
					{
						visited[ny][nx] = visited[y][x];
						q.push(1000 * ny + nx);
					}
					else if (a[ny][nx] == '1')
					{
						visited[ny][nx] = visited[y][x] + 1;
						temp.push(1000 * ny + nx);
					}
					else if (a[ny][nx] == '#')
					{
						visited[ny][nx] = visited[y][x];
						return;
					}
				}
			}
			q = temp;
		}
	}
	int main()
	{
		ios_base::sync_with_stdio(false);
		cout.tie(NULL); cin.tie(NULL);
		cin >> n >> m;
		cin >> x1 >> y1 >> x2 >> y2;
		--x1, --y1, --x2, --y2;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> a[i][j];
			}
		}

		bfs(x1, y1);

		cout << visited[x2][y2];
	}
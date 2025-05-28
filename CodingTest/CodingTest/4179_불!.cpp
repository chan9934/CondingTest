#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int r, c, ret, J_y, J_x;
bool flag;
char a[1004][1004];
int visited[1004][1004];
int fire[1004][1004];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0 ,-1 };

void J_bfs(int y, int x)
{
	visited[y][x] = 0;
	queue <pair< int, int >> q;
	q.push({ y, x });

	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c)
			{
				ret = min(ret, visited[y][x] + 1);
				flag = 1;
				continue;
			}
			if (visited[ny][nx] != -1)continue;
			if (a[ny][nx] != '#')
			{
				if (fire[ny][nx] == -1 || fire[ny][nx] > visited[y][x] + 1)
				{
					visited[ny][nx] = visited[y][x] + 1;
					q.push({ ny, nx });
				}
			}
		}
	}
}
void F_bfs(int y, int x)
{
	fire[y][x] = 0;
	queue <pair< int, int >> q;
	q.push({ y, x });
	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c )continue;
			if (fire[ny][nx] != -1)continue;
			if (a[ny][nx] != '#')
			{
				fire[ny][nx] = fire[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c;

	fill(&visited[0][0], &visited[0][0] + 1004 * 1004, -1);
	fill(&fire[0][0], &fire[0][0] + 1004 * 1004, -1);
	ret = r * c;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> a[i][j];

			if (a[i][j] == 'J')
				J_y = i, J_x = j;
		}
	}
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (a[i][j] == 'F' && fire[i][j] == -1)
				F_bfs(i, j);
		}
	}
	J_bfs(J_y, J_x);
	if (flag)
		cout << ret;
	else
		cout << "IMPOSSIBLE";
	return 0;
}
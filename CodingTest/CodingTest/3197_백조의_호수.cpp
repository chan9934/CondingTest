#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int r, c;
const int max_n = 1500;
char a[max_n + 4][max_n + 4];
int visited[max_n + 4][max_n + 4];
int l_visited[max_n + 4][max_n + 4];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> l_position;
bool bfs(int y, int x, int level)
{
	visited[y][x] = level;

	for (int i = 0; i < 4; ++i)
	{
		if (a[y][x] == '.')
		{
			return true;
		}
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny>= r || nx >= c)continue;
		if (visited[ny][nx] == level)continue;
		if (a[ny][nx] == '.')
		{
			a[y][x] = '.';
		}
	}
	return false;
}
void connect(bool& success, int y, int x)
{
	cout << "y : " << y << " x : " << x << "\n";
	if (y == l_position[1].first && x == l_position[1].second)
	{
		success = true;
	}
	if (success)
		return;
	l_visited[y][x] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny>= r || nx >= c)continue;
		if (l_visited[ny][nx])continue;
		if (a[ny][nx] != 'X')
		{
			connect(success, ny, nx);
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
			if (a[i][j] == 'L')
				l_position.push_back({ i, j });
		}
	}

	int level = 1;
	while (true)
	{
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (a[i][j] == 'X' && visited[i][j] != level)
				{
					bfs(i, j, level);
				}
			}
		}
		bool success = false;
		connect(success, l_position[0].first, l_position[0].second);

		if (success)
			break;
		fill(&l_visited[0][0], &l_visited[0][0] + (max_n + 4) * (max_n + 4), 0);
		++level;
	}
	cout << level;
	return 0;
}


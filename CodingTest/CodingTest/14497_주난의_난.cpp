#include <iostream>

using namespace std;

#define y1 actual_y1
int n, m;
int x1, y1, x2, y2;
char a[304][304];
int visited[304][304];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x, int level)
{
	visited[y][x] = level;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny > n || nx > m)continue;
		if (visited[ny][nx] == level)continue;
		cout << "ny : " << ny << " nx " << nx << "\n";
		if (a[ny][nx] == '1')
		{
			a[ny][nx] = '0';
			visited[ny][nx] = level;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					cout <<  a[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";
		}
		else
			dfs(ny, nx, level);
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
	int level = 1;
	while(true)
	{
		dfs(x1 - 1, y1 - 1, level);
		if(visited[x2 - 1][y2 - 1])
		{
			cout << level;
			break;
		}
		++level;
	}
	return 0;
}
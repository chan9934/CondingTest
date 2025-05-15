#include <iostream>
#include <cstring>

using namespace	std;

int n;
int min_h, max_h;
int ret_number;

int a[104][104];
bool visited[104][104];

int dy[] = {-1, 0, 1, 0};
int dx[] = { 0, 1, 0, -1 };

void go(int h, int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (a[ny][nx] <= h)continue;
		if (visited[ny][nx] == true)continue;
		go(h, ny, nx);
	}
}

int main()
{
	cin >> n;

	min_h = 100;
	max_h = 1;
	ret_number = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int h = 0;
			cin >> h;
			a[i][j] = h;
			min_h = min(min_h, h);
			max_h = max(max_h, h);
		}
	}
	for (int h = min_h; h <= max_h; ++h)
	{
		int number = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (a[i][j] > h && visited[i][j] == false)
				{
					go(h, i, j);
					++number;
				}
			}
		}
		memset(visited, false, sizeof(visited));
		ret_number = max(ret_number, number);
	}
	cout << ret_number;
	return 0;
}
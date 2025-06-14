#include <iostream>

using namespace std;

int n, ret;
int visited[14][14];
int a[14][14];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
bool check(int y, int x)
{
	if (visited[y][x])return false;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx])return false;
	}
	return true;
}
void go(int here, int cnt)
{
	if (cnt == 3)
	{
		int temp = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (visited[i][j])
					temp += a[i][j];
			}
		}
		ret = min(ret, temp);
		return;
	}
	for (int i = here; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!check(i, j))continue;

			visited[i][j] = 1;
			for (int k = 0; k < 4; ++k)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];

				visited[ny][nx] = 1;
			}
			go(i, cnt + 1);
			visited[i][j] = 0;
			for (int k = 0; k < 4; ++k)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];

				visited[ny][nx] = 0;
			}
		}
	}
}
int main()
{
	cin >> n;

	ret = n * n * 200;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}
	go(0, 0);
	cout << ret;
	return 0;
}
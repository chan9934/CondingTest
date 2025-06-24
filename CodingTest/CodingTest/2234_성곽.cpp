#include <iostream>

using namespace std;

int n, m, ret_1, ret_2, ret_3;
int a[51][51];
int visited[51][51];

pair<int, int> get_direction(int index)
{
	if (index == 0)
	{
		return { 0, -1 };
	}
	else if (index == 1)
	{
		return { -1, 0 };
	}
	else if (index == 2)
	{
		return { 0, 1 };
	}
	else
	{
		return { 1, 0 };
	}
}

int go(int y, int x)
{
	int target = a[y][x];
	int ret = 1;
	for (int i = 0; i < 4; ++i)
	{
		if (!(target & (1 << i)))
		{
			pair<int, int>p = get_direction(i);

			int ny = y + p.first;
			int nx = x + p.second;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (visited[ny][nx] == 1)continue;
			visited[ny][nx] = 1;
			ret += go(ny, nx);
		}
	}
	return ret;
}
int main()
{
	cin >> m >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (visited[i][j] != 1)
			{
				visited[i][j] = 1;
				++ret_1;
				ret_2 = max(ret_2, go(i, j));
			}
		}
	}
	cout << ret_1 << "\n";
	cout << ret_2 << "\n";
	return 0;
}
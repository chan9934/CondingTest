#include <iostream>

using namespace std;

int n, m, ret_1, ret_2, ret_3;
int a[51][51];
int visited[51][51];
int compSize[2504];

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

int go(int y, int x, int cnt)
{
	int target = a[y][x];
	int ret = 1;
	visited[y][x] = cnt;
	for (int i = 0; i < 4; ++i)
	{
		if (!(target & (1 << i)))
		{
			pair<int, int>p = get_direction(i);

			int ny = y + p.first;
			int nx = x + p.second;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (visited[ny][nx] != 0)continue;
			ret += go(ny, nx, cnt);
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
			if (visited[i][j] == 0)
			{
				++ret_1;
				compSize[ret_1] = go(i, j, ret_1);
				ret_2 = max(ret_2, compSize[ret_1]);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (i + 1 < n)
			{
				int a = visited[i + 1][j];
				int b = visited[i][j];
				if (a != b)
				{
					ret_3 = max(ret_3, compSize[a] + compSize[b]);
				}
			}
			if (j + 1 < m)
			{
				int a = visited[i][j + 1];
				int b = visited[i][j];
				if (a != b)
				{
					ret_3 = max(ret_3, compSize[a] + compSize[b]);
				}
			}
		}
	}
	cout << ret_1 << "\n";
	cout << ret_2 << "\n";
	cout << ret_3 << "\n";
	return 0;
}
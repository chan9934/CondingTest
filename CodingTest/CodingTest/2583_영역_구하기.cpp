#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define y1 y1_define
int a[104][104];
int visited[104][104];
int m, n, k;
int x1, x2, y1, y2;
vector<int>ret;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int dfs(int y, int x)
{
	visited[y][x] = 1;
	int cnt = 1;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
		if (a[ny][nx] == 1)continue;
		if (visited[ny][nx] == 1)continue;
		cnt += dfs(ny, nx);
	}
	return cnt;
}
int main()
{
	cin >> m >> n >> k;

	for (int i = 0; i < k; ++i)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int y = y1; y < y2; ++y)
		{
			for (int x = x1; x < x2; ++x)
			{
				a[y][x] = 1;
			}
		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(a[i][j] != 1 && visited[i][j] == 0)
			{
				int cnt = dfs(i, j);
				ret.push_back(cnt);
			}
		}
	}
	cout << ret.size() << "\n";
	sort(ret.begin(), ret.end());
	for (int element : ret)
	{
		cout << element << " ";
	}

}
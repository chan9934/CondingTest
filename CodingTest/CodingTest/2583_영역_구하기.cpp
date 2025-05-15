#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool a[104][104];
bool visited[104][104];
int m, n, k, ret;
int s_y, s_x, e_y, e_x;
vector<int>ret_v;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x, int& cnt)
{
	visited[y][x] = true;
	++cnt;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (a[ny][nx] == true)continue;
		if (visited[ny][nx] == true)continue;
		dfs(ny, nx, cnt);
	}
}
int main()
{
	cin >> m >> n >> k;

	for (int t = 0; t < k; ++t)
	{
		cin >> s_y >> s_x >> e_y >> e_x;
		for (int i = s_y; i < e_y; ++i)
		{
			for (int j = s_x; j < e_x; ++j)
			{
				a[i][j] = true;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] == false && visited[i][j] == false)
			{
				int cnt = 0;
				dfs(i, j, cnt);
				++ret;
				ret_v.push_back(cnt);
			}
		}
	}
	cout << ret << "\n";
	sort(ret_v.begin(), ret_v.end());
	for (int element : ret_v)
	{
		cout << element << " ";
	}

}
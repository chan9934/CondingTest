#include <iostream>
#include <vector>

using namespace std;

int n, m;

int a[10][10];
bool visited[10][10];
vector<pair<int, int>>e_v;
int e_num, ret;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };


int dfs(int y, int x)
{
	visited[y][x] = true;

	int num = 1;
	if (a[y][x] == 2)
		num = 0;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
		if (a[ny][nx] != 1 && visited[ny][nx] == false)
		{
			num += dfs(ny, nx);
		}
	}
	return num;
}


int find()
{
	int cnt = e_num;
	cnt -= 3;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] == 2 && visited[i][j] == false)
			{
				cnt -= dfs(i, j);
			}
		}
	}
	return cnt;
}
void draw()
{

	cout << "\n";
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
			if (a[i][j] == 0)
			{
				++e_num;
				e_v.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < e_num; ++i)
	{
		for (int j = i + 1; j < e_num; ++j)
		{
			for (int k = j + 1; k < e_num; ++k)
			{
				int y1 = e_v[i].first;
				int x1 = e_v[i].second;
				int y2 = e_v[j].first;
				int x2 = e_v[j].second;
				int y3 = e_v[k].first;
				int x3 = e_v[k].second;

				a[y1][x1] = 1;
				a[y2][x2] = 1;
				a[y3][x3] = 1;

				/*int temp = find();

				if (ret < temp)
				{
					ret = temp;
					draw();
				}*/

				ret = max(ret, find());
				a[y1][x1] = 0;
				a[y2][x2] = 0;
				a[y3][x3] = 0;
				fill(&visited[0][0], &visited[0][0] + 10 * 10, false);
			}
		}
	}
	cout << ret;
	return 0;
}
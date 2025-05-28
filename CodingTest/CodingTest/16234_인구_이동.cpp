#include <iostream>
#include <vector>

using namespace std;

int n, l, r, ret;

int a[104][104];
int visited[104][104];


int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x, vector<pair<int, int>>& v_p)
{
	visited[y][x] = 1;
	v_p.push_back({ y,x });
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
		if (visited[ny][nx] == 1) continue;

		int temp = abs(a[ny][nx] - a[y][x]);
		if (temp >= l && temp <= r)
		{
			dfs(ny, nx, v_p);
		}
	}
}

void adjust(const vector<pair<int, int>>& v_p)
{
	if (v_p.size() <= 1)
		return;

	int sum = 0;
	int num = 0;

	for (auto p : v_p)
	{
		sum += a[p.first][p.second];
		++num;
	}

	int avg = sum / num;
	for (auto p : v_p)
	{
		a[p.first][p.second] = avg;
	}
}

int main()
{

	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> n >> l >> r;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}
	while (true)
	{
		bool finish = true;
		vector < vector<pair<int, int>>> teams;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (visited[i][j] == 0)
				{
					vector<pair<int, int>>v_p;
					dfs(i, j, v_p);
					if (v_p.size() > 1)
					{
						teams.push_back(v_p);
						finish = false;
					}
				}
			}
		}
		for (auto v_p : teams)
		{
			adjust(v_p);

		}
		if (finish)
			break;
		else
		{
			fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
			++ret;
			/*cout << '\n';
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					cout << a[i][j] << " ";
				}
				cout << '\n';
			}*/
		}
	}

	cout << ret;
	return 0;
}
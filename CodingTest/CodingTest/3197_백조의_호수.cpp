	#include <iostream>
	#include <queue>
	#include <vector>

	using namespace std;

	int r, c;
	const int max_n = 1500;
	char a[max_n + 4][max_n + 4];
	int visited_water[max_n + 4][max_n + 4], visited_swan[max_n + 4][max_n + 4];

	queue<pair<int, int>>swan_q, swan_temp_q, water_q, water_temp_q;
	int dy[] = { -1, 0, 1, 0 };
	int dx[] = { 0, 1, 0, -1 };

	bool move_swan()
	{
		while (swan_q.size())
		{
			int y = swan_q.front().first;
			int x = swan_q.front().second;
			swan_q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= r || nx >= c)continue;

				if (visited_swan[ny][nx])continue;
				visited_swan[ny][nx] = 1;
				if (a[ny][nx] == 'X')
				{
					swan_temp_q.push({ ny, nx });
				}
				else if (a[ny][nx] == '.')
				{
					swan_q.push({ ny, nx });
				}
				else if (a[ny][nx] == 'L')
				{
					return true;
				}
			}
		}
		swan_q = swan_temp_q;
		queue<pair<int, int>>().swap(swan_temp_q);
		return false;
	}

	void melt_ice()
	{
		while (water_q.size())
		{
			int y = water_q.front().first;
			int x = water_q.front().second;
			water_q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= r || nx >= c)continue;

				if (visited_water[ny][nx])continue;
				visited_water[ny][nx] = 1;
				if (a[ny][nx] == 'X')
				{
					water_temp_q.push({ ny, nx });
					a[ny][nx] = '.';
				}
			}
		}
		water_q = water_temp_q;
		queue<pair<int, int>>().swap(water_temp_q);
	}

	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);
		cin >> r >> c;

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cin >> a[i][j];
				if (a[i][j] == '.')
				{
					water_q.push({ i, j });
					visited_water[i][j] = 1;

				}
				else if (a[i][j] == 'L' )
				{
					water_q.push({ i, j });
					if(swan_q.empty())
					{
						swan_q.push({ i, j });
						visited_swan[i][j] = 1;
					}
				}
			}
		}

		int count = 0;
		while (true)
		{
			if (move_swan())
			{
				cout << count;
				break;
			}
			melt_ice();
			++count;
		}
		return 0;
	}
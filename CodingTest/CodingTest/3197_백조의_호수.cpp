#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int r, c;
const int max_n = 1500;
char a[max_n + 4][max_n + 4];
int visited_water[max_n + 4][max_n + 4], visited_swan[max_n + 4][max_n + 4];
queue<pair<int, int>>water_q, water_temp_q, swan_q, swan_temp_q;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void q_clear(queue<pair<int, int>>& q)
{
	queue<pair<int, int>>().swap(q);
}

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

			if (ny < 0 || nx < 0 || ny >= r || ny >= x)continue;
			if (visited_swan[ny][nx])continue;
			visited_swan[y][x] = 1;
			if (a[ny][nx] == 'L') return true;
			if (a[ny][nx] == '.')swan_q.push({ ny, nx });
			else if(a[ny][nx] == 'X')swan_temp_q.push({ ny, nx });
		}
	}
	return false;
}
void move_water()
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

			if (ny < 0 || nx < 0 || ny >= r || ny >= x)continue;
			if (visited_water[ny][nx])continue;
			visited_water[y][x] = 1;
			if (a[ny][nx] == '.')water_q.push({ ny, nx });
			else water_temp_q.push({ ny, nx });
		}
	}
}
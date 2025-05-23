#include <iostream>
#include <vector>

using namespace std;

int n, m;

int a[10][10];
bool visited[10][10];
int e_num;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int dfs(int y, int x)
{
	visited[y][x] = true;

	int num = 0;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
		if (a[ny][nx] == 0 && visited[ny][nx] == false)
		{
			num = dfs(ny, nx);
			++num;
		}
	}
	return num;
}
int main()
{
	for (int i = 0; i < e_num; ++i)
	{
		for (int j = i + 1; j < e_num; ++j)
		{
			for (int k = j + 1; k < e_num; ++k)
			{

			}
		}
	}
	return 0;
}
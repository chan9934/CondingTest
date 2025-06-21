#include <iostream>
#include <bitset>

using namespace std;
int r, c, ret = 1;
char a[21][21];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int check;

void print_check()
{
	cout << bitset<8>(check) << "\n";
}
void dfs(int y, int x, int num)
{
	ret = max(ret, num);
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		int bit = (a[ny][nx] - (int)('A'));
		if (check & (1 << bit))continue;

		check |= (1 << bit);
		dfs(ny, nx, num + 1);
		check ^= (1 << bit);
	}
}

int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> a[i][j];
		}
	}
	check |= (1 << (a[0][0] - (int)('A')));
	dfs(0, 0, 1);

	cout << ret << "\n";
	return 0;

}
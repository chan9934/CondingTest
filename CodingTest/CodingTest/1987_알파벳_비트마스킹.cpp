#include <iostream>
#include <bitset>

using namespace std;

int check;
char a[24][24];
int r, c;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void print_check()
{
	cout << bitset<16>(check) << "\n";
}

int go(int y, int x)
{
	int ret = 1;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c)continue;
		if (check & (1 << int(a[ny][nx] - (int)('A'))))continue;

		check |= (1 << int(a[ny][nx] - (int)('A')));
		print_check();
		ret += go(ny, nx);
	}
	return ret;
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
	check |= (1 << int(a[0][0] - (int)('A')));
	print_check();
	cout << go(0, 0) << "\n";
	return 0;
}
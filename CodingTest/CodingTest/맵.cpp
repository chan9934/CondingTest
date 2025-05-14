#include <iostream>

using namespace std;

//int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
//int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
//int main()
//{
//	int x = 0, y = 0;
//	for (int i = 0; i < sizeof(dy) / sizeof(int); ++i)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//		cout << ny << " : " << nx << "\n";
//	}
//}
int n;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

bool visited[3][3];
int a[3][3];

void go(int y, int x)
{
	visited[y][x] = true;

	cout << "y : " << y << " x : " << x << "\n";

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
		if (a[ny][nx] == 0 || visited[ny][nx])continue;
		go(ny, nx);
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}
	go(0, 0);
}
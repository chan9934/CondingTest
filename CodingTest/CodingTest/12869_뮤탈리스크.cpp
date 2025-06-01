#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, ret;
int a[3];
int visited[10][10][10];
int d[6][3] = {
	{9,3,1},
	{9,1,3},
	{3,9,1},
	{3,1,9},
	{1,3,9},
	{1,9,3},
};
struct A {
	int a, b, c;
};
int bfs(int a, int b, int c)
{
	visited[a][b][c] = 1;
	queue<A> q;
	q.push({ a,b,c });

	while (q.size())
	{
		a = q.front().a;
		b = q.front().b;
		c = q.front().c;
		q.pop();
		if (visited[0][0][0]) break;
		for (int i = 0; i < 6; ++i)
		{
			int na = max(0, a - d[i][0]);
			int nb = max(0, b - d[i][1]);
			int nc = max(0, c - d[i][2]);
			if (visited[na][nb][nc])continue;
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({ na, nb, nc });
		}
	}
	return visited[0][0][0] - 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << bfs(a[0], a[1], a[2]) << "\n";
	return 0;
}
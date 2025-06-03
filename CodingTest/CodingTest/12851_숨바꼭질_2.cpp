#include <iostream>
#include <queue>

using namespace std;

int n, k, ret, cnt;
int visited[100004];

void bfs(int x)
{
	visited[x] = 1;
	queue<int>q;
	q.push(x);

	auto func = [&](int current, int nx)
		{
			if (nx == k)
			{
				ret = visited[current];
				++cnt;
				return;
			}
			if (nx < 0 || nx > 100000) return;
			if (visited[nx] == 0)
				visited[nx] = visited[current] + 1;
			q.push(nx);
		};
	while (q.size())
	{
		x = q.front();
		q.pop();

		if (cnt != 0)
		{
			if (visited[x] > ret)
				return;
		}
		int nx_1 = x + 1;
		func(x, nx_1);
		int nx_2 = x - 1;
		func(x, nx_2);
		int nx_3 = x * 2;
		func(x, nx_3);
	}
}

int main()
{
	cin >> n >> k;
	bfs(n);
	cout << ret << '\n' << cnt;
}
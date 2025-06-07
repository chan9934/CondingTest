#include <iostream>
#include <queue>

using namespace std;

int n, k;

int visited[100004];
int cnt[100004];

void bfs(int x)
{
	queue<int>q;
	q.push(x);
	visited[x] = 1;

	while (q.size())
	{
		x = q.front();
		q.pop();
		for (int i : { x - 1, x + 1, x * 2})
		{
			if (i < 0 || i > 100000)continue;

			if (visited[i] == 0)
			{
				visited[i] = visited[x] + 1;
				q.push(i);
				++cnt[i];
			}
			else if (visited[i] == visited[x] + 1)
			{
				q.push(i);
				++cnt[i];
			}
		}
	}
}
int main()
{
	cin >> n >> k;
	if (n == k)
	{
		cout <<0 << "\n" << 1;
		return 0;
	}
	bfs(n);
	cout << visited[k] -1 << "\n" << cnt[k];
	return 0;
}
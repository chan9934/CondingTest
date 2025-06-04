#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k, ret;

int visited[100004];
vector<vector<int>> v;

void bfs(int x)
{
	queue<int> q;
	q.push(x);

	while (q.size())
	{
		x = q.front();
		q.pop();

		for (int i : { x - 1, x + 1, x * 2})
		{
			if (i < 0 || i > 100000)continue;
		}
	}

}

int main()
{
	cin >> n >> k;

	bfs(n);
	return 0;
}
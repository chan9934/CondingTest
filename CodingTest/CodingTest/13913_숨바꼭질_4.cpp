#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
#define prev aaa
#define next aaaa

int n, k, ret;

const int max_n = 200004;

int visited[max_n], prev[max_n];

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	visited[x] = 1;

	while (q.size())
	{
		x = q.front();
		q.pop();
		for (int i : { x - 1, x + 1, x * 2})
		{
			if (i < 0 || i > max_n)continue;

			if (visited[i] == 0)
			{
				visited[i] = visited[x] + 1;
				prev[i] = x;
				if (i == k)
					return;
				q.push(i);
			}
		}
	}

}

int main()
{
	cin >> n >> k;
	if (n == k)
	{
		cout << 0 << "\n" << n;
		return 0;
	}

	bfs(n);

	cout << visited[k] - 1 << '\n';

	vector<int> ret;
	for (int i = k; i != n; i = prev[i])
	{
		ret.push_back(i);
	}
	ret.push_back(n);
	reverse(ret.begin(), ret.end());	
	for (int element : ret)
	{
		cout << element << " ";
	}
	return 0;
}
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int n, k, ret;

int visited[100004];
map<int, int> m;

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
			if (i < 0 || i > 100000)continue;

			if (visited[i] == 0)
			{
				visited[i] = visited[x] + 1;
				m[i] = x;
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
	ret.push_back(k);
	int index = m[k];
	ret.push_back(index);
	while (true)
	{
		if (m.end() != m.find(index))
		{
			index = m[index];
			ret.push_back(index);
		}
		else break;
	}
	reverse(ret.begin(), ret.end());
	for (int element : ret)
	{
		cout << element << " ";
	}
	return 0;
}
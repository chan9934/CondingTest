#include <iostream>
#include <queue>

using namespace std;

int n, k, ret;

const int max_n = 500004;
int visited[max_n];

pair<int, int> dn[] = { {-1, 1}, {1, 1},{0, 2} };

void bfs(int here)
{
	queue<int>q;
	q.push(here);
	visited[here] = 1;

	int current_level = 0;
	while (q.size())
	{
		int qsize = q.size();
		++current_level;
		k += current_level;
		for (int i = 0; i < qsize; ++i)
		{
			here = q.front();
			q.pop();

			for (int i = 0; i < 3; ++i)
			{
				int next = (here * dn[i].second) + dn[i].first;

				if (current_level <= 6)
				{
					cout << "next : " << next << " here : " << here << " Current_level : " << current_level << " k : " << k << "\n";
				}
				if (next < 0 || next > 500000)continue;

				if (next == k)
				{
					ret = current_level;
					return;
				}
				visited[next] = visited[here] + 1;
				q.push(next);
			}
		}
	}
}
int main()
{
	cin >> n >> k;

	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	if (n == k)
	{
		cout << 0;
		return 0;
	}
	ret = -1;
	bfs(n);

	cout << ret;

	return 0;
}
	#include <iostream>
	#include <queue>

	using namespace std;

	int n, k, t;

	const int max_n = 500000;

	int visited[2][max_n + 4];

	bool bfs(int here)
	{
		visited[0][here] = 1;

		queue<int>q;
		q.push(here);

		while (q.size())
		{
			int qsize = q.size();
			++t;
			k += t;
			if (k > max_n)
				return false;

			if (visited[t % 2][k])
			{
				return true;
			}
			for (int i = 0; i < qsize; ++i)
			{
				here = q.front();
				q.pop();

				for(int next : {here + 1, here -1, here * 2})
				{
					if (next < 0 || next > max_n)continue;
					if (next == k)
						return true;
					if (visited[t % 2][next])continue;
					visited[t % 2][next] = 1;
					q.push(next);
				}
			}
		}
		return false;
	}

	int main()
	{
		cin >> n >> k;

		if (n == k)
		{
			cout << "0";
			return 0;
		}
		if (!bfs(n))
			cout << -1;
		else
			cout << t;
		return 0;
	}
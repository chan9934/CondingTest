	#include <iostream>
	#include <queue>

	using namespace std;

	int n, a, b, c;

	int visited[64][64][64];

	int dn[6][3]
	{
		{9, 3, 1},
		{9, 1, 3},
		{3, 9, 1},
		{3, 1, 9},
		{1, 3, 9},
		{1, 9, 3}
	};

	struct triple
	{
		int a;
		int b;
		int c;
	};

	int dfs()
	{
		queue<triple>q;
		q.push({ a,b,c });
		visited[a][b][c] = 1;
		while (q.size())
		{
			triple tri = q.front();
			q.pop();
			a = tri.a;
			b = tri.b;
			c = tri.c;
			if (a == 0 && b == 0 && c == 0)
				return visited[a][b][c]-1;
			for (int i = 0; i < 6; ++i)
			{
				int na = max(0, a - dn[i][0]);
				int nb = max(0, b - dn[i][1]);
				int nc = max(0, c - dn[i][2]);

				if (visited[na][nb][nc] == 0)
				{
					q.push({ na,nb,nc });
					visited[na][nb][nc] = visited[a][b][c] + 1;
				}
			}
		}
	}

	int main()
	{
		cin >> n;

		for (int i = 0; i < n; ++i)
		{

			if (i == 0)
				cin >> a;
			else if (i == 1)
				cin >> b;
			else if (i == 2)
				cin >> c;
		}
		cout << dfs() << '\n';
	}
#include <iostream>
#include <vector>

using namespace std;

//const int v = 6;
//vector<int> adj[v];
//int visited[v];
//
//void dfs(int from)
//{
//	cout << "from : " << from << "\n";
//
//	visited[from] = 1;
//
//	for (int to : adj[from])
//	{
//		if (visited[to] != 1)
//			dfs(to);
//	}
//	cout << from << "로부터 시작된 함수가 종료되었습니다.\n";
//	return;
//}
//int main()
//{
//	adj[1].push_back(2);
//	adj[1].push_back(3);
//	adj[2].push_back(4);
//	adj[2].push_back(5);
//	adj[4].push_back(2);
//
//	dfs(1);
//}

int n, m, ret;
vector<vector<int>>a, visited;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void dfs(int y, int x)
{
	if (visited[y][x] == 1)
		return;

	visited[y][x] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (a[ny][nx] == 0)continue;
		dfs(ny, nx);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		vector<int>c;
		vector<int>vis;
		for (int j = 0; j < m; ++j)
		{
			int check = 0;
			cin >> check;
			c.push_back(check);
			vis.push_back(0);
		}
		a.push_back(c);
		visited.push_back(vis);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] == 1 && visited[i][j] == 0)
			{
				dfs(i, j);
				++ret;
			}
		}
	}
	cout << ret;
}
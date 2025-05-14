#include <iostream>
#include <vector>

using namespace std;

const int v = 6;
vector<int> adj[v];
int visited[v];

void dfs(int from)
{
	cout << "from : " << from << "\n";

	visited[from] = 1;

	for (int to : adj[from])
	{
		if (visited[to] != 1)
			dfs(to);
	}
	cout << from << "로부터 시작된 함수가 종료되었습니다.\n";
	return;
}
int main()
{
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[2].push_back(5);
	adj[4].push_back(2);

	dfs(1);
}
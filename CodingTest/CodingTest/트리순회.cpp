#include <iostream>
#include <vector>
using namespace std;

vector<int>adj[104];
int visited[104];

void postOrder(int here)
{
	if (visited[here] == 0)
	{
		if (adj[here].size() == 1)
		{
			postOrder(adj[here][0]);
		}
		else if (adj[here].size() == 2)
		{
			postOrder(adj[here][0]);
			postOrder(adj[here][1]);
		}
		visited[here] = 1;
		cout << here << ' ';
	}
}
void preOrder(int here)
{
	if (visited[here] == 0)
	{
		visited[here] == 1;
		cout << here << ' ';
		if (adj[here].size() == 1)
		{
			preOrder(adj[here][0]);
		}
		else if (adj[here].size() == 2)
		{
			preOrder(adj[here][0]);
			preOrder(adj[here][1]);
		}
	}
}
void inOrder(int here)
{
	if (visited[here] == 0)
	{
		if (adj[here].size() >= 1)
		{
			inOrder(adj[here][0]);
		}
		visited[here] == 1;
		cout << here << ' ';
		if (adj[here].size() == 2)
		{
			inOrder(adj[here][1]);
		}
	}
}
int main()
{
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[2].push_back(5);
	int root = 1;
	cout << "\n 트리순회 : postOrder \n";
	postOrder(root);
	memset(visited, 0, size(visited));
	cout << "\n 트리순회 : preOrder \n";
	preOrder(root);
	memset(visited, 0, size(visited));
	cout << "\n 트리순회 : inOrder \n";
	inOrder(root);
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

const int Vertex = 10;

vector<int> adj[Vertex];
bool Visited[Vertex];


void go(int from)
{
	Visited[from] = true;

	cout << from << "\n";

	for (int there : adj[from])
	{
		if (Visited[there])continue;
		go(there);
	}
}

int main()
{
	adj[1].push_back(2);
	adj[2].push_back(1);
	adj[1].push_back(3);
	adj[3].push_back(1);
	adj[3].push_back(4);
	adj[4].push_back(3);

	for (int i = 0; i < Vertex; ++i)
	{
		if (adj[i].size() && !Visited[i])
			go(i);
	}
	return 0;
}
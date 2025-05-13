#include <iostream>

using namespace std;

const int Vertex = 10;
bool Matrix[Vertex][Vertex];
bool Visited[Vertex];

void go(int from)
{
	Visited[from] = true;
	cout << from << "\n";
	for (int i = 0; i < from; ++i)
	{
		if (Visited[i]) continue;
		if (Matrix[from][i])
			go(i);
	}
}

int main()
{
	Matrix[1][2] = 1;
	Matrix[2][1] = 1;
	Matrix[1][3] = 1;
	Matrix[3][1] = 1;
	Matrix[3][4] = 1;
	Matrix[4][3] = 1;

	for (int i = 0; i < Vertex; ++i)
	{
		for (int j = 0; j < Vertex; ++j)
		{
			if (Matrix[i][j] && !Visited[i])
			{
				go(i);
			}
		}
	}
	return 0;
}
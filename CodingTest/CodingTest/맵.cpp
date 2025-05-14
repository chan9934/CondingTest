#include <iostream>

using namespace std;

int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int main()
{
	int x = 0, y = 0;
	for (int i = 0; i < sizeof(dy) / sizeof(int); ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		cout << ny << " : " << nx << "\n";
	}
}
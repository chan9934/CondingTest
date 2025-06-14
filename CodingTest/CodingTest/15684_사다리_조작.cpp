#include <iostream>

using namespace std;

int n, m, h, a, b, ret;
int visited[34][34];

bool check()
{
	for (int i = 1; i < n; ++i)
	{
		int next = i;
		for (int j = 1; j <= h; ++j)
		{
			if (visited[j][next]) ++next;
			else if (visited[j][next - 1]) --next;
		}
		if (next != i) return false;
	}
	return true;
}
void go(int here, int cnt)
{
	if (cnt >= ret || cnt > 3)return;
	if (check())
	{
		ret = min(ret, cnt);
	}
	for (int i = here; i <= h; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (visited[i][j] || visited[i][j + 1] || visited[i][j - 1])continue;
			visited[i][j] = 1;
			go(i, cnt + 1);
			visited[i][j] = 0;
		}
	}
}

int main()
{
	ret = 10;

	cin >> n >> m >> h;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		visited[a][b] = 1;
	}
	go(1, 0);
	
	cout << (ret > 3 ? -1 : ret);
}
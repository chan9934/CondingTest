#include <iostream>
#include <vector>

using namespace std;

int n, m, h;

int a[14][300];

void combination(int r, vector<int>&v, int s_index)
{
	if (v.size() == s_index)
	{
		return;
	}
	for (int i = s_index + 1; i < n * m; ++i)
	{
		v.push_back(i);
		combination(r, v, i);
		v.pop_back();
	}
}

void go(int x)
{

}
int main()
{
	cin >> n >> m >> h;
	for (int i = 0; i < h; ++i)
	{
		int y = 0;
		int x = 0;
		cin >> y >> x;
		a[y][x] = 1;
	}
	if (m == 0)
	{
		cout << 0;
		return 0;
	}

	return 0;
}
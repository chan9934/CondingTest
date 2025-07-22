#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ret;
int a[101];
void go(vector<int>indiceis, int start_index)
{
	if (indiceis.size() == 3)
	{
		int temp_ret = 0;
		for (const int index : indiceis)
		{
			temp_ret += a[index];
		}
		if (temp_ret <= m)
		{
			ret = max(ret, temp_ret);
		}
		return;
	}
	for (int i = start_index + 1; i < n; ++i)
	{
		indiceis.push_back(i);
		go(indiceis, i);
		indiceis.pop_back();
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	vector<int>v;
	go(v, -1);
	cout << ret << "\n";
	return 0;
}
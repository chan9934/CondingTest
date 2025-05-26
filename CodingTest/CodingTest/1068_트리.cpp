#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, r, root;
vector<int>a[54];

int dfs(int here)
{
	int number = 0;
	int child = 0;
	for (int there : a[here])
	{
		if (there == r)
			continue;
		number += dfs(there);
		++child;
	}
	if (child == 0)
		++number;
	
	return number;
}
int main()
{
	cin >> n;

	int temp = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		if (temp == -1) root = i;
		else a[temp].push_back(i);
	}
	cin >> r;
	if (r == root)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << dfs(root);
	return 0;
}
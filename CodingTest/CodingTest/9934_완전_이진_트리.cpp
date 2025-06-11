#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int k;
int a[11];
vector<int> ret[11];

void go(int s_index, int e_index, int level)
{
	if (s_index > e_index) return;
	if (s_index == e_index)
	{
		ret[level].push_back(a[s_index]);
		return;
	}
	int mid = (s_index + e_index) / 2;
	ret[level].push_back(a[mid]);
	go(s_index, mid - 1, level + 1);
	go(mid + 1, e_index, level + 1);
}

int main()
{
	cin >> k;
	int depth = pow(2, k) - 1;
	for (int i = 0; i < depth; ++i)
	{
		cin >> a[i];
	}
	go(0, depth - 1, 0);

	for (int i = 0; i < k; ++i)
	{
		for (auto element : ret[i])
		{
			cout << element << " ";
		}
		cout << "\n";
	}
	return 0;
}
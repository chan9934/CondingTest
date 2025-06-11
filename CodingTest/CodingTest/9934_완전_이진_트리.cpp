#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int k;
vector<int>v;
vector<int> ret[11];

void go(vector<int>v, int level)
{
	if (v.size() == 1)
	{
		ret[level].push_back(v[0]);
		return;
	}
	ret[level].push_back(v[v.size() / 2 ]);

	vector<int>left;
	vector<int>right;
	for (int i = 0; i < (int)v.size() / 2; ++i)
	{
		left.push_back(v[i]);
	}
	for (int i = (int)v.size() / 2 + 1; i < (int)v.size(); ++i)
	{
		right.push_back(v[i]);
	}
	go(left, level + 1);
	go(right, level + 1);
}

int main()
{
	cin >> k;
	int depth = pow(2, k) - 1;
	for (int i = 0; i < depth; ++i)
	{
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}
	go(v, 0);

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
#include <iostream>
#include <vector>

using namespace std;

int n, ret;
vector<int> v;

void permutation(vector<int> temp, int depth, int level)
{
	if(depth == n)
	{
		temp[0] -= 9;
		temp[1] -= 3;
		temp[2] -= 1;
		for (int i = 0; i < n; ++i)
		{
			if (temp[i] > 0)
				break;
			if (i == n - 1)
			{
				ret = min(level, ret);
				return;
			}
		}
		permutation(temp, 0, level + 1);
		cout << level + 1 << "\n";
		
		return;
	}

	for (int i = depth; i < n; ++i)
	{
		swap(temp[i], temp[depth]);
		permutation(temp, depth + 1, level);
		swap(temp[i], temp[depth]);
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}
	ret = 100;
	permutation(v, 0, 0);
	cout << ret;
}
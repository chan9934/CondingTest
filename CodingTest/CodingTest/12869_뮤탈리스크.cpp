#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ret;
vector<int>v;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}
	while (true)
	{
		++ret;
		sort(v.begin(), v.end());
		if (n == 3)
		{

			if (v[1] == 9)
			{
				v[0] -= 1;
				v[1] -= 9;
				v[2] -= 3;
			}
			else
			{
				v[0] -= 1;
				v[1] -= 3;
				v[2] -= 9;
			}
		}
		else if (n == 2)
		{
			v[0] -= 3;
			v[1] -= 9;
		}
		else
		{
			v[0] -= 9;
		}

		bool finish = true;
		for (int element : v)
		{
			if (element > 0)
			{
				finish = false;
				break;
			}
		}
		if (finish)
		{
			cout << ret;
			break;
		}
	}
	return 0;
}
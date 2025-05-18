#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int t, n;
map<int, pair<int, int>>container;
pair<int, int>get(int number)
{
	pair<int, int>ret;
	while (number % 2 == 0)
	{
		number /= 2;
		++ret.first;
	}
	while (number % 5 == 0)
	{
		number /= 5;
		++ret.second;
	}
	return ret;
}
pair<int, int> fac(int number)
{
	int index = 0;
	while (true)
	{
		number == 0;
	}
	while (container.size() <  number + 1)
	{
		if (container.empty() || container.size() == 1)
		{
		}
		else
		{
			pair<int, int>ret = get((container.size() + 1));
			if (ret.first == 0 && ret.second == 0)
			{

			}
			pair<int, int>ret_before = *(container.end() - 1);
			ret.first += ret_before.first;
			ret.second += ret_before.second;
			container.push_back(ret);
		}
	}
	return container[number];
}
int main()
{
	cin >> t;
	
	for (int i = 0; i < t; ++i)
	{
		cin >> n;
		pair<int, int>get = fac(n);
		int left = get.first;
		int right = get.second;

		int ret = min(left, right);
		cout << ret << "\n";
	}

	return 0;
}
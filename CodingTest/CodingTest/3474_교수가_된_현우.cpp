#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int t, n;
pair<int, int>get(int number)
{
	pair<int, int>ret;
	bool fin_two = false;
	bool fin_five = false;
	while (true)
	{
		if (!fin_two)
		{
			if (number % 2 == 0)
			{
				number /= 2;
				++ret.first;
			}
			else
			{
				fin_two = true;
			}
		}
		if (!fin_five)
		{
			if (number % 5 == 0)
			{
				number /= 5;
				++ret.second;
			}
			else
			{
				fin_five = true;
			}
		}
		if (fin_two && fin_five)
			break;
	}
	return ret;
}
pair<int, int> fac(int number)
{
	pair<int, int>ret;
	for (int i = 2; i <= number;)
	{
		cout << i << "\n";
		pair<int, int>temp = get(i);
		ret.first += temp.first;
		ret.second += temp.second;
		i = i + 2;
		if(i % 10 == 0)
			i = i + 2;
	}
	for (int i = 5; i <= number;)
	{
		cout << i << "\n";
		pair<int, int>temp = get(i);
		ret.first += temp.first;
		ret.second += temp.second;
		i = i + 5;
	}
	return ret;
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
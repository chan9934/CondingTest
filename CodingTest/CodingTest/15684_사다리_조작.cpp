#include <iostream>

using namespace std;

int n, m, h;
int a[14][34];

bool check(int num, int depth)
{
	int check_num = num;
	while (true)
	{
		if (depth == h)
		{
			if (a[num][depth])
			{
				if (num + 1 == check_num)
					return true;
			}
			else if (num - 1 >= 1 && a[n - 1][depth])
			{
				if (num - 1 == check_num)
					return true;
			}
			return false;
		}
		if (a[num][depth])
		{
			num = num + 1;
			depth = depth + 1;
		}
		else if (n - 1 >= 1 && a[n - 1][depth])
		{
			num = num - 1;
			depth = depth + 1;
		}
		else
		{
			depth = depth + 1;
		}
	}
}

int main()
{
	cin >> n >> m >> h;
	for (int i = 0; i < m; ++i)
	{
		int left = 0;
		int depth = 0;
		cin >> left >> depth;
		a[left][depth] = 1;
	}
	int current_check_num = 1;
	while(current_check_num <= 3)
	{
		for (int i = 1; i <= n * h; ++i)
		{
			if (current_check_num >= 2)
			{
				for (int j = i + 1; j <= n * h; ++j)
				{
					if (current_check_num >= 3)
					{
						for (int k = j + 1; k <= n * h; ++k)
						{

						}
					}
				}
			}
			else
			{
				int
			}
		}
		++current_check_num;
	}
	return 0;
}
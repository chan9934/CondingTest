#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int a, b, c;
long long ret;
long long ret_2;
queue<int> get_square_values()
{
	queue<int> ret_values;
	int value = b;
	int index = 0;
	while (true)
	{
		if (value & 1)
		{
			ret_values.push(index);
			--value;
		}

		++index;
		value /= 2;
		if (value == 1)
		{
			ret_values.push(index);
			return ret_values;
		}
	}
}
int main()
{
	cin >> a >> b >> c;
	int square_value = a % c;
	if (b == 1)
	{
		cout << square_value;
		return 0;
	}
	if (b == 0)
	{
		cout << 1;
		return 0;
	}
	queue<int> queue_values = get_square_values();
	if (square_value == 0)
	{
		cout << 0;
		return 0;
	}
	int index = 0;
	ret_2 = 1;
	while (true)
	{
		if (queue_values.empty())
			break;
		if (queue_values.front() == index)
		{
			ret_2 *= square_value;
			ret_2 %= c;
			queue_values.pop();
		}
		square_value *= square_value;
		square_value = square_value % c;

		++index;
	}
	cout << ret_2 % c;
	return 0;
}

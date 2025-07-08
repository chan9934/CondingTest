#include <iostream>

using namespace std;

int max_value, index, temp, n = 9;

int main()
{
	for (int i = 1; i <= n; ++i)
	{
		cin >> temp;
		if (max_value < temp)
		{
			index = i;
			max_value = temp;
		}
	}
	cout << max_value << "\n" << index << "\n";
	return 0;
}
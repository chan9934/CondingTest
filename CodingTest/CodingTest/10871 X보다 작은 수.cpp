#include <iostream>

using namespace std;

int n, x, temp;

int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		if (temp < x)
		{
			cout << temp << " ";
		}
	}
	return 0;
}
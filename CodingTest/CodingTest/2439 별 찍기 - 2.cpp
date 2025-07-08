#include <iostream>

using namespace std;

int n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = n; j > 0; --j)
		{
			if (i >= j)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
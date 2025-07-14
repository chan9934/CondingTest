#include <iostream>

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	bool increase = true;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= n - 1 + (i); ++j)
		{
			if (j >= n - 1 - (i))cout << '*';
			else cout << ' ';

		}
		cout << "\n";
	}
	for (int i = n - 2; i >= 0; --i)
	{
		for (int j = 0; j <= n - 1 + (i); ++j)
		{
			if (j >= n - 1 - (i))cout << '*';
			else cout << ' ';

		}
		cout << "\n";
	}
	return 0;
}
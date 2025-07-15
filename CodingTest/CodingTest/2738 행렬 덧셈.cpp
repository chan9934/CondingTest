#include <iostream>

using namespace std;

int n, m;
int a[101][101], b[101][101];

int main()
{
	cin >> n >> m;
	for (int j = 0; j < n; ++j)
	{
		for (int k = 0; k < m; ++k)
		{
			cin >> a[j][k];
		}
	}
	for (int j = 0; j < n; ++j)
	{
		for (int k = 0; k < m; ++k)
		{
			cin >> b[j][k];
		}
	}

	for (int j = 0; j < n; ++j)
	{
		for (int k = 0; k < m; ++k)
		{
			cout << a[j][k] + b[j][k] << " ";
		}
		cout << "\n";
	}
	return 0;
}
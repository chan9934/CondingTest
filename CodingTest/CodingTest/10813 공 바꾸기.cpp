#include <iostream>

using namespace std;

int n, m, b, c;
int a[101];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		a[i] = i;
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> b >> c;
		swap(a[b], a[c]);
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << a[i] << " ";
	}
	return 0;
}
#include <iostream>

using namespace std;
int n, m, num;
int a[20000004];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		num += 10000000;

		++a[num];
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> num;
		cout << a[num + 10000000];
		if (i != m - 1)
			cout << " ";
	}
	return 0;
}
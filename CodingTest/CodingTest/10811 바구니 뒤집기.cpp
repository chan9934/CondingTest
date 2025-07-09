#include <iostream>

using namespace std;

int n, m, b, c;
int a[101];
int main()
{
	cin >> n >> m;
	auto print = []()
		{
			for (int i = 1; i <= n; ++i)
			{
				cout << a[i] << " ";
			}
			cout << "\n";
		};
	for (int i = 1; i <= n; ++i)
	{
		a[i] = i;
	}
	for (int i = 1; i <= m; ++i)
	{
		cin >> b >> c;
		reverse(a + b, a + c + 1);
		print();
	}
	return 0;
}
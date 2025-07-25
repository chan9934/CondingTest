#include <iostream>

using namespace std;

bool a[20000004];
int n, number, m, check_number;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> number;
		a[number + 10000000] = true;
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> check_number;
		if (a[check_number + 10000000] == true)
		{
			cout << "1" << " ";
		}
		else
		{
			cout << "0" << " ";
		}
	}
	return 0;
}
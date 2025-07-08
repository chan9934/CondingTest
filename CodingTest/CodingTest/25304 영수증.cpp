#include <iostream>

using namespace std;

int x, n, a, b;
int main()
{
	cin >> x >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		x -= a * b;
	}
	if (x == 0)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
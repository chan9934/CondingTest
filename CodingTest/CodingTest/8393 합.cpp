#include <iostream>

using namespace std;

int n, t;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		t += i;
	}
	cout << t;
	return 0;
}
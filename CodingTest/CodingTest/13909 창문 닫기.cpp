#include <iostream>

using namespace std;

typedef long long ll;

ll n;
ll ret;
int main()
{
	cin >> n;

	for (int i = 1; i * i <= n; ++i)
	{
		++ret;
	}
	cout << ret << "\n";
	return 0;
}
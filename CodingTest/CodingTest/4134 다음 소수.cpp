#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
ll n, t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> t;
	for (ll i = 0; i < t; ++i)
	{
		cin >> n;
		if (n <= 2) 
		{
			cout << 2 << "\n";
			continue;
		}
		else if (!(n & 1))
		{
			++n;
		}

		while (true)
		{
			bool pass = true;
			for (ll j = 3; j*j <= n; j+=2)
			{
				if (n % j == 0)
				{
					pass = false;
					break;
				}
			}
			if (pass)
			{
				cout << n << "\n";
				break;
			}
			n += 2;
		}
	}
	return 0;
}
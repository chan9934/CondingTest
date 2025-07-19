#include <iostream>
#include <vector>

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	while (cin >> n)
	{
		if (n == -1)
			break;
		vector<int>v;
		int temp = n;
		for (int i = 1; i <= n; ++i)
		{
			if (n % i == 0 && n != i)
			{
				v.push_back(i);
				temp -= i;

			}
		}
		if (temp == 0)
		{
			cout << n << " = ";
			for (int i = 0; i < v.size(); ++i)
			{
				cout << v[i];
				if (i != v.size() - 1)
				{
					cout << " + ";
				}
				else
				{
					cout << "\n";
				}
			}
		}
		else
		{
			cout << n << " is NOT perfect." << "\n";
		}
	}
	return 0;
}
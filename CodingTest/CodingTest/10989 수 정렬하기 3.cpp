#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, number;
int a[10004];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> number;
		++a[number];
	}
	for (int i = 0; i < size(a); ++i)
	{
		while (a[i] > 0)
		{
			cout << i << "\n";
			--a[i];
		}
	}
	return 0;
}

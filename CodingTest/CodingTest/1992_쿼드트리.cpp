#include<iostream>

using namespace std;

int n;
char a[68][68];

string quard(int y, int x, int size)
{
	if (size == 1)
		return string(1, a[y][x]);

	char chk = a[y][x];
	for (int i = y; i < y + size; ++i)
	{
		for (int j = x; j < x + size; ++j)
		{
			if (chk != a[i][j])
			{
				return '('
					+ quard(y, x, size / 2)
					+ quard(y, x + size / 2, size / 2)
					+ quard(y + size / 2, x, size / 2)
					+ quard(y + size / 2, x + size / 2, size / 2)
					+ ')';
			}
		}
	}
	return string(1, a[y][x]);
}
int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}
	cout << quard(0, 0, n);
	return 0;
}
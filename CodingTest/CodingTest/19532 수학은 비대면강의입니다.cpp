#include <iostream>

using namespace std;

int a, b, c, d, e, f, x, y;

int main()
{
	cin >> a >> b >> c >> d >> e >> f;

	for (int i = 0; i < 1999; ++i)
	{
		for (int j = 0; j < 1999; ++j)
		{
			x = -999 + i;
			y = -999 + j;
			if ((a * (x) + b * (y) == c) && (d * (x) + e * (y) == f))
			{
				cout << x << " " << y << "\n";
				return 0;
			}
		}
	}
	return 0;
}
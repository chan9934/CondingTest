#include <iostream>
#include <set>

#define y1 aaaaa
using namespace std;

int x1, y1, x2, y2, x3, y3, x4, y4;
set<int>s;

int main()
{
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if (x1 != x2)
	{
		if (x2 == x3)
		{
			x4 = x1;
		}
		else
		{
			x4 = x2;
		}
	}
	else
	{
		x4 = x3;
	}
	if (y1 != y2)
	{
		if (y2 == y3)
		{
			y4 = y1;
		}
		else
		{
			y4 = y2;
		}
	}
	else
	{
		y4 = y3;
	}
	cout << x4 << " " << y4 << "\n";
	return 0;
}
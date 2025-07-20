#include <iostream>

#define y1 aaaa
using namespace std;

int n, x1, y1, min_x, min_y, max_x, max_y;

int main()
{
	cin >> n;
	min_x = min_y = 100000;
	max_x = max_y = -100000;
	for (int i = 0; i < n; ++i)
	{
		cin >> x1 >> y1;
		min_x = min(min_x, x1);
		min_y = min(min_y, y1);
		max_x = max(max_x, x1);
		max_y = max(max_y, y1);
	}
	cout << (max_x - min_x) * (max_y - min_y) << "\n";
	return 0;คน
}
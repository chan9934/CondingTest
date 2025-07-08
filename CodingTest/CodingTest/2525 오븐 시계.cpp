#include <iostream>

using namespace std;

int h, m, c, t;
int main()
{
	cin >> h >> m >> c;
	t = h * 60 + m;
	t += c;
	if (t >= 24 * 60)
	{
		t -= 24 * 60;
	}
	h = t/ 60;
	t = t% 60;
	cout << h << " " << t;
	return 0;
}
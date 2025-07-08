#include <iostream>

using namespace std;

int h, m, t;

int main()
{
	cin >> h >> m;
	t = h * 60 + m;
	t -= 45;

	if (t < 0)
	{
		t += 24 * 60;
	}
	h = t / 60;
	m = t % 60;
	cout << h << " " << m;
	return 0;
}
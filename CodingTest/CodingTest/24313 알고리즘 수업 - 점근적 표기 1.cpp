#include <iostream>

using namespace std;

int a1, a0, c, n0;
int main()
{
	cin >> a1 >> a0 >> c >> n0;

	bool success = true;
	for (int i = n0; i <= 100; ++i)
	{
		if ((i * a1) + a0 > c * i) success = false;
		if (!success)
			break;
	}
	cout << success << "\n";
	return 0;
}
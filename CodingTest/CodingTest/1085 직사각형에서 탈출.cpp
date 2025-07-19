#include <iostream>

using namespace std;

int x, y, w, h, ret;
int main()
{
	cin >> x >> y >> w >> h;
	ret = 1000;
	ret = min(ret, abs(x - 0));
	ret = min(ret, abs(y - 0));
	ret = min(ret, abs(x - w));
	ret = min(ret, abs(y - h));
	cout << ret << "\n";
	return 0;
}
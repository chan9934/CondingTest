#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int a, b, c;
int  go(int a, int b)
{
	if (b == 1)
		return a % c;

	long long ret = go(a, b / 2);
	ret = (ret * ret) % c;
	if (b & 1) ret = (ret * a) % c;
	return ret;

}
int main()
{
	cin >> a >> b >> c;
	cout << go(a, b);
	return 0;
}
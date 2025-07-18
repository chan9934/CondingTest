#include <iostream>

using namespace std;
typedef long long ll;
int a, b, ret;
ll v;
int main()
{
	cin >> a >> b >> v;
	ret = ceil((double)(((double)(v - a) / (double)(a - b)) + 1));
	cout << ret << "\n";
	return 0;
}
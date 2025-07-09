#include <iostream>

using namespace std;

int n, m;
float ret;
int a[1004];

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		m = max(m, a[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		ret += ((float)(a[i]) / (float)(m)) * 100;
	}
	ret /= n;
	printf("%.10f", ret);
	return 0;
}
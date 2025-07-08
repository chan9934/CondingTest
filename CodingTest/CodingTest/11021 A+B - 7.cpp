#include <iostream>

using namespace std;

int a, b, t;

int main()
{
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		scanf("%d %d", &a, &b);
		int c = a + b;
		printf("Case #%d: %d\n", i, (c));
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int m, n, x;

char s[11];

int main()
{
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%s %d", &s, &x);
		
		if (strcmp(s, "add") == 0)
		{
			n |= (1 << (x - 1));
		}
		else if (strcmp(s, "remove") == 0)
		{
			n &= ~(1 << (x - 1));
		}
		else if (strcmp(s, "check") == 0)
		{
			printf_s("%d\n", (n & (1 << x - 1) ? 1 : 0));
		}
		else if (strcmp(s, "toggle") == 0)
		{
			n ^= (1 << (x - 1));
		}
		else if (strcmp(s, "all") == 0)
		{
			n = (1 << 20) - 1;
		}
		else if (strcmp(s, "empty") == 0)
		{
			n = 0;
		}

	}
}
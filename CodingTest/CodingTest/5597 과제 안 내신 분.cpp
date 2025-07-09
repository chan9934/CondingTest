#include <iostream>

using namespace std;

int a[31];
int temp;
int main()
{
	for (int i = 1; i <= 28; ++i)
	{
		cin >> temp;
		a[temp] = 1;
	}
	for (int i = 1; i <= 30; ++i)
	{
		if (a[i] == 0)
			cout << i << "\n";
	}
	return 0;
}
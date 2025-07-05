#include <iostream>

using namespace std;

int n, ret;

int a[500004], b[500004];

int main()
{
	// Number of People
	cin >> n;

	// Add heights to a_array
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	
	// Count visible pairs 
	for (int i = 1; i < n; ++i)
	{
		(a[i - 1] > a[i]) ? ret += 1, b[i] = 1 : ret += b
	}

	return 0;
}
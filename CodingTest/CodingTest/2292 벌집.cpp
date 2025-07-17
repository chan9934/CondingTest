#include <iostream>

using namespace std;

typedef long long ll;

ll n, sum;
int idx;
int main()
{
	cin >> n;
	
	sum = 1;
	idx = 1;
	while (n > sum)
	{
		sum += (6 * idx);
		++idx;
	}
	cout << idx;
	return 0;
}
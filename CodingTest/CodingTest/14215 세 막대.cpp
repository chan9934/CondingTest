#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
int temp;
int main()
{
	for (int i = 0; i < 3; ++i)
	{
		cin >> temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());
	if (a[0] + a[1] <= a[2])
	{
		a[2] = a[0] + a[1] - 1;
	}
	cout << a[0] + a[1] + a[2] << "\n";

	return 0;
}
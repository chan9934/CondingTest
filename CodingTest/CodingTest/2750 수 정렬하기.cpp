#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, number;
vector<int> v;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> number;
		v.push_back(number);
	}
	sort(v.begin(), v.end());
	for (const int element : v)
	{
		cout << element << "\n";
	}
	return 0;
}
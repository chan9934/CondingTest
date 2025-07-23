#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, x;
vector<int >v;
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(), [](int first, int second) {
		return first > second;
		});
	cout << v[k - 1] << "\n";
	return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int x, n;
vector<int>order;
map<int, int>cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x;
		order.push_back(x);
	}
	vector<int>sort_order = order;

	sort(sort_order.begin(), sort_order.end());
	sort_order.erase(unique(sort_order.begin(), sort_order.end()), sort_order.end());
	for (int x : order)
	{
		cout << lower_bound(sort_order.begin(), sort_order.end(), x) - sort_order.begin() << " ";
	}
	cout << "\n";
	return 0;
}
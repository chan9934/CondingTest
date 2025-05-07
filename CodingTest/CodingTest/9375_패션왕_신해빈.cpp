#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
string a, b;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> m;
		map<string, int> type_number;
		for (int j = 0; j < m; ++j)
		{
			cin >> a >> b;
			type_number[b]++;
		}
		long long ret = 1;
		for (auto number : type_number)
		{
			ret *= (long long)(number.second + 1);
		}

		--ret;
		cout << ret << "\n";

	}
	return 0;

}
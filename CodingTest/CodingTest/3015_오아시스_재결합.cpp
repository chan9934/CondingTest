#include <iostream>
#include <stack>

typedef long long ll;

using namespace std;

ll ret, n, cnt, temp;

stack<pair<ll, ll>>stk;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	// Input : number of people
	cin >> n;

	cnt = 1;
	// Compute heights
	for (int i = 0; i < n; ++i)
	{
		// Input : height
		cin >> temp;

		cnt = 1;
		while (!stk.empty() && stk.top().first <= temp)
		{
			ret += stk.top().second;
			if (stk.top().first == temp)
			{
				cnt = stk.top().second + 1;
			}
			else
			{
				cnt = 1;
			}
			stk.pop();
		}
		if (!stk.empty())
			++ret;
		stk.push({ temp ,cnt });
	}
	cout << ret;
	return 0;
}
#include <iostream>
#include <stack>

using namespace std;


typedef long long ll;
ll n, ret, temp;

stack <pair<ll,ll>>stk;

int main()
{
	// Number of People
	cin >> n;

	// Sort
	for (int i = 0; i < n; ++i)
	{
		// add person
		cin >> temp;
		int cnt = 1;
		// Stack top is shorter than temp
		while (stk.size() && stk.top().first <= temp)
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
		if(stk.size())++ret;
		stk.push({temp, cnt});
	}

	cout << ret << '\n';
	return 0;
}
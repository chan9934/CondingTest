#include <iostream>
#include <stack>

using namespace std;


typedef long long ll;
ll n, ret, temp;

stack <ll>stk;

int main()
{
	// Number of People
	cin >> n;

	// Sort
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		while (stk.size() && stk.top() < temp)
		{
			ret += 1;
			stk.pop();
		}
		if(stk.size())++ret;
		stk.push(temp);
	}

	cout << ret << '\n';
	return 0;
}
#include <iostream>
#include <stack>
#include <bitset>

using namespace std;
int n,ret;
string s;
stack<int>stk;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	stk.push(-1);
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '(')
		{
			stk.push(i);
		}
		else
		{
			stk.pop();
			if(!stk.empty())
			{
				ret = max(ret, i - stk.top());
			}
		}
	}
	cout << ret << "\n";
	return 0;
}


#include <iostream>
#include <stack>
#include <bitset>

using namespace std;
int a[200004];
int n, max_cnt, cnt;
string s;
stack<int>stk;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;

	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '(')
		{
			stk.push(i);
		}
		else
		{
			if(!stk.empty())
			{
				a[stk.top()] = a[i] = 1;
				stk.pop();
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == 1)
		{
			++cnt;
		}
		else
		{
			max_cnt = max(max_cnt, cnt);
			cnt = 0;
		}
	}
	max_cnt = max(max_cnt, cnt);
	cout << max_cnt << "\n";
	return 0;
}


#include <iostream>
#include <stack>

using namespace std;

int n, ret;
string s;
stack<int> stk;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	// input string length
	cin >> n;

	// input string
	cin >> s;
	// count max ret
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (stk.empty() && (s[i] == ')'))
		{
			ret = max(ret, cnt);
			cnt = 0;
			continue;
		}
		if ((s[i] == ')') && !stk.empty())
		{
			cnt += 2;
			stk.pop();
		}
		else if(s[i] == '(')
		{
			stk.push(i);
		}
	}
	ret = max(ret, cnt);
	cout << ret << "\n";
	return  0;
}
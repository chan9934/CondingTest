#include <iostream>
#include <stack>

using namespace std;

stack<int> stk;
string s;
int n, ret;
int main()
{

	// Input : length and string
	cin >> n >> s;

	// initialize base index for valid substring
	stk.push(-1);
	// Calculate max ret
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '(')
		{
			// push index of opening bracket
			stk.push('(');
		}
		else
		{
			// pop the matching opening bracket
			stk.pop();
			if (!stk.empty())
			{
				// update max valid length
				ret = max(ret, i - stk.top());
			}
			else
			{
				// no base index, set current as new base
				stk.push(i);
			}
		}
	}

	// output the result
	cout << ret << "\n";
	return 0;
}
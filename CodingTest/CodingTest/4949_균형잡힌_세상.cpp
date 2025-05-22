#include <iostream>
#include <stack>
#include <string>

using namespace std;
string s;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		getline(cin, s);
		if (s == ".")
			break;
		stack<char> stk;
		bool check = true;
		for (char c : s)
		{
			if (c == ']')
			{
				if (stk.empty() || stk.top() == '(')
				{
					check = false;
					break;
				}
				stk.pop();
				continue;
			}
			if (c == ')')
			{
				if (stk.empty() || stk.top() == '[')
				{
					check = false;
					break;
				}
				stk.pop();
				continue;
			}
			if (c == '[') stk.push(c);
			if (c == '(') stk.push(c);
		}
		if (check && stk.empty())
			cout << "yes\n";
		else
			cout << "no\n";

		s.clear();
	}
	return 0;
}
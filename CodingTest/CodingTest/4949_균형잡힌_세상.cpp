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
		if (s == string(1, '.'))
			break;
		stack<char> stk;
		for (char c : s)
		{
			if (c == '.' || c == ' ')
				continue;
			if ((int('a') <= int(c) && int('z') >= int(c)) || (int('A') <= int(c) && int('Z') >= int(c)))
				continue;
			if (!stk.empty())
			{
				char top = stk.top();
				if (top == ']' || top == ')')
					break;
				if (c == ']' && top == '[')
				{
					stk.pop();
					continue;
				}
				else if (c == ')' && top == '(')
				{
					stk.pop();
					continue;
				}
			}
			stk.push(c);
		}
		if (stk.empty())
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";

		s.clear();
	}
	return 0;
}
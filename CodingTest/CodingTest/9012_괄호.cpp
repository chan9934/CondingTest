#include <iostream>
#include <stack>

using namespace std;

int t;
string s;

int main()
{
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> s;
		stack<char> container;
		for (char c : s)
		{
			if (!container.empty())
			{
				if (c == ')')
				{
					if (container.top() == '(')
					{
						container.pop();
						continue;
					}
				}
			}
			container.push(c);
		}
		if (container.empty())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}
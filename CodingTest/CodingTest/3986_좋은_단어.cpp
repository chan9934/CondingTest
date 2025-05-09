#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n, ret;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{

		stack<char>stack_chr;
		string str;
		cin >> str;
		for (char chr : str)
		{
			if (!stack_chr.empty())
			{
				if (chr == stack_chr.top())
				{
					stack_chr.pop();
					continue;
				}
			}
			stack_chr.push(chr);
		}
		if (stack_chr.empty()) ++ret;
	}
	cout << ret;
	return 0;
}
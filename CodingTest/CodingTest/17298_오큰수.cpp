#include <iostream>
#include <stack>
using namespace std;

int n, a; int arr[1000004];
int ret[1000004];
stack<int> stk;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		arr[i] = a;
		while (!stk.empty())
		{
			int top_index = stk.top();
			if (arr[top_index] < a)
			{
				ret[top_index] = a;
				stk.pop();
			}
			else
				break;
		}
		stk.push(i);
	}
	while (!stk.empty())
	{
		int top_index = stk.top();
		ret[top_index] = -1;
		stk.pop();
	}
	for (int i = 0; i < n; ++i)
	{
		cout << ret[i] << " ";
	}
	return 0;
}
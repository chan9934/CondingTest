#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int n, a; int arr[1000004];
int ret[1000004];
stack<int> stk;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	fill(&ret[0], &ret[0] + size(ret), -1);
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
	for (int i = 0; i < n; ++i)
	{
		cout << ret[i] << " ";
	}
	return 0;
}
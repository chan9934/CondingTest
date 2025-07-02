#include <iostream>
#include <stack>

using namespace std;

stack<char>ret;
string a, b;

int main()
{
	cin >> a >> b;
	if (b.size() > a.size())
	{
		swap(a, b);
	}
	int size = a.size();
	int depth = size - b.size();
	int add_value = 0;
	int value = 0;
	for (int i = size - 1; i >= 0; --i)
	{
		if(i - depth >= 0)
		{
			value = (a[i] - '0') + (b[i - depth] - '0') + add_value;
		}
		else
		{
			value = (a[i] - '0') + add_value;
		}
		add_value = value/10;
		ret.push((value % 10 + '0'));
	}
	if(add_value != 0)
		ret.push((add_value + '0'));

	while (ret.size())
	{
		cout << ret.top();
		ret.pop();
	}
	return 0;
}
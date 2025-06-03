#include <iostream>
#include <vector>

using namespace std;

int n, ret;

vector<int>num;
vector<char>oper;

int calculate(char oper, int l_value, int r_value)
{
	if (oper == '+')return l_value + r_value;
	else if (oper == '-')return l_value - r_value;
	else if (oper == '*')return l_value * r_value;
}

void go(int here, int l_value)
{
	if (here == num.size() - 1)
	{
		ret = max(ret, l_value);
		return;
	}

	go(here + 1, calculate(oper[here],  l_value, num[here + 1]));
	if (here + 2 <= num.size() - 1)
	{
		int temp = calculate(oper[here + 1], num[here + 1], num[here + 2]);
		go(here + 2, calculate(oper[here], l_value, temp));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ret = INT32_MIN;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		char c;
		cin >> c;
		if (i & 1)
			oper.push_back(c);
		else
			num.push_back(c - '0');
	}

	go(0, num[0]);
	cout << ret << "\n";
	return 0;
}
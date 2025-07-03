#include <iostream>
#include <stack>
#include <bitset>

using namespace std;
int a[200004];
int n, m, max_cnt, cnt;
char c;
stack<char>s;
void change_bit(int index)
{
	m |= (1 << index);
	while ((index != 0) && (m & (1 << index)))
	{
		--index;
	}
	m |= (1 << index);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> c;
		if (c == ')' && (!s.empty() && s.top() == '('))
		{
			s.pop();
			change_bit(i);

		}
		else
		{
			s.push(c);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (m & (1 << i))
		{
			++cnt;
		}
		else
		{
			max_cnt = max(max_cnt, cnt);
			cnt = 0;
		}
	}
	max_cnt = max(max_cnt, cnt);
	cout << max_cnt << "\n";
	return 0;
}


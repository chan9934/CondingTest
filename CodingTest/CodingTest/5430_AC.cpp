#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t, n;
char c;
string p, s;
int f_d, l_d, cnt;
vector<int> v;
int main()
{
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> p;
		f_d = 0, l_d = 0, cnt = 0;
		for (char element : p)
		{
			if (element == 'R')
			{
				++cnt;
			}
			else if (element == 'D')
			{
				if (cnt & 1)
				{
					++l_d;
				}
				else
				{
					++f_d;
				}
			}
		}
		cin >> n;
		v.clear();
		cin >> s;
		int temp = 0;
		for (char element : s)
		{
			if (element == '[')
				continue;
			if (element == ',' || element == ']')
			{
				if (temp != 0)
					v.push_back(temp);
				temp = 0;
			}
			else
			{
				temp = temp * 10 + (element - '0');
			}
		}

		if (l_d + f_d > n)
		{
			cout << "error" << "\n";
			continue;
		}
		v.erase(v.begin(), v.begin() + f_d);
		v.erase(v.end() - l_d, v.end());

		if (cnt & 1)
		{
			reverse(v.begin(), v.end());
		}
		cout << '[';
		for (int j = 0; j < v.size(); ++j)
		{
			cout << v[j];
			if (j != v.size() - 1)
				cout << ',';
		}
		cout << ']' << "\n";
	}
	return 0;
}
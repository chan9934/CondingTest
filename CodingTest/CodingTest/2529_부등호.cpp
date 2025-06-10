#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int k;
vector<string>ret;

char c[10];
bool visited[11];

bool oper(char left, char right, char c)
{
	if (c == '<')
	{
		return left < right;
	}
	else if (c == '>')
	{
		return left > right;
	}
	return false;
}

void go(string s, int depth)
{
	if (depth == k + 1)
	{
		cout << s << " " << depth << "\n";
		ret.push_back(s);
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		if (visited[i])continue;
		if (s.empty() || oper(*(s.end() - 1), i + '0', c[depth -1]))
		{
			visited[i] = true;
			s.push_back(i + '0');
			go(s, depth + 1);
			visited[i] = false;
			s.pop_back();
		}
	}
}
int main()
{
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> c[i];
	}
	go(string(), 0);
	sort(ret.begin(), ret.end());
	cout << *(ret.end() - 1) << "\n";
	cout << *(ret.begin()) << "\n";
	return 0;
}
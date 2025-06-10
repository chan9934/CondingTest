#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int k;
vector<string>ret;
int visited[11];
char oper[11];

bool calcul(char left, char right, char oper)
{
	if (oper == '<')
		return left < right;
	else
		return left > right;
}
void go(string value, int index)
{
	if (index - 1 == k)
	{
		ret.push_back(value);
		return;
	}

	for (int i = 0; i <= 9; ++i)
	{
		if (visited[i] == 1)continue;

		char right = i + '0';
		if (value.empty() || calcul(*(value.end() - 1), right, oper[index - 1]))
		{
			visited[i] = 1;
			value.push_back(right);
			go(value, index + 1);

			visited[i] = 0;
			value.pop_back();
		}
	}
}
int main()
{
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> oper[i];
	}
	go(string(), 0);
	sort(ret.begin(), ret.end());

	cout << *(ret.end() - 1) << "\n" << *ret.begin();
}
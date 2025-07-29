#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> m1;
map<int, string>m2;

int n, m;
string str;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> str;
		m1[str] = i;
		m2[i] = str;
	}
	for (int i = 1; i <= m; ++i)
	{
		cin >> str;
		int num = atoi(str.c_str());
		if (num == 0)
		{
			cout << m1[str] << "\n";
		}
		else
		{
			cout << m2[num] << "\n";
		}
	}

	return 0;
}
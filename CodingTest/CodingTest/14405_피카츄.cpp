#include <iostream>
#include <queue>

using namespace std;

string s;
int flag;
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
	{
		if (i < s.size() - 1 && (s.substr(i, 2) == "pi" || s.substr(i, 2) == "ka")) i += 1;
		else if (i < s.size() - 2 && (s.substr(i, 3) == "chu")) i += 2;
		else
		{
			flag = 1; break;
		}
	}
	if (!flag)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
	return 0;
}
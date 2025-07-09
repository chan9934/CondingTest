#include <iostream>

using namespace std;

string s, p;
int t, r;

int main()
{
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> r >> s;
		for (int j = 0; j < s.size(); ++j)
		{
			for (int k = 0; k < r; ++k)
			{
				cout << s[j];
			}
		}
		cout << "\n";
	}
	return 0;
}
#include <iostream>
#include <queue>

using namespace std;

string n;
string s;
int main()
{
	cin >> n;
	for (int i = 0; i < n.size(); ++i)
	{
		s += n[i];
		if (s == "pi")
		{
			s = "";
		}
		else if(s == "ka")
		{
			s = "";
		}
		else if(s == "chu")
		{
			s = "";
		}
		else
		{
			if (s.size() > 3)
			{
				break;
			}
		}
	}
	if (s.empty())
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
	return 0;
}
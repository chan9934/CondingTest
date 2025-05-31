#include <iostream>
#include <string>

using namespace std;

int n;

string ret;

int main()
{
	cin >> n;
	int i = 666;
	while (true)
	{
		ret = to_string(i);
		if (string::npos != ret.find("666"))
		{
			--n;

			if (n == 0)
			{
				cout << ret;
				break;
			}
		}
		++i;
	}
	return 0;
}
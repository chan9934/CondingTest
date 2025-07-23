#include <iostream>
#include <string>

using namespace std;

int n, cnt;

int main()
{
	cin >> n;
	
	for (int i = 666; i <= 66666666; ++i)
	{
		if (string::npos != to_string(i).find("666"))
		{
			++cnt;
			if (cnt == n)
			{
				cout << i << "\n";
				break;
			}
		}
	
	}
	return 0;
}
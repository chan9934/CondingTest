#include <iostream>

using namespace std;

int n;
bool ret;
int main()
{
	cin >> n;
	if (n % 4 == 0)
	{
		if (n % 100 != 0)
		{
			ret = true;
		}	
		else if (n % 400 == 0)
		{
			ret = true;
		}
	}
	cout << int(ret) << "\n";
	return 0;
}
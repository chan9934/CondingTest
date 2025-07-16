#include <iostream>
#include <cmath>

using namespace std;

int b, ret;
string n;
int main()
{
	cin >> n >> b;

	for (int i = 0; i < (int)n.size(); ++i)
	{
		int temp = 0;
		if (n[i] >= 'A')
			temp = n[i] - 'A' + 10;
		else
			temp = n[i] - '0';
		ret *= b;
		ret += temp;
	}
	cout << ret << "\n";
	return 0;
}
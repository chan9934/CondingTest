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
		if (n[(int)n.size() - 1 - i] >= 'A')
			temp = n[(int)n.size() - 1 - i] - 'A' + 10;
		else
			temp = n[(int)n.size() - 1 - i] - '0';
		ret += temp * pow(b, i);
	}
	cout << ret << "\n";
	return 0;
}
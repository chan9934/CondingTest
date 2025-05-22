#include <iostream>
#include <string>

using namespace std;

int n, f, b, s, r;

string ret;

int main()
{
	cin >> n;

	s = n / 17;
	r = n % 17;
	
	if (r <= 6)
	{
		f = s + r -1;
		b = 6;
	}
	else
	{
		f = s * 10 + 6;
		b = r - 7;
	}
	ret = to_string(f) + "66" + to_string(b);
	cout << ret << endl;
	return 0;
}
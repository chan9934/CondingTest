#include <iostream>
#include <string>

using namespace std;

int n, f, b, s, r;

string ret;

int main()
{
	while(true)
	{
		cin >> n;

		s = n / 16;
		r = n % 16;
		if (r <= 6)
		{
			if (s == 0)
			{
				f = r - 1;
			}
			else
			{
				f = (s - 1) * 10 + 6 + r + 1;
			}
			b = 6;
		}
		else
		{
			if (s == 0)
			{
				f =  6;
			}
			else
			{
				f = (s - 1) * 10 + 6;
			}
			b = r - 7;
		}
		ret = to_string(f) + "66" + to_string(b);
		cout << ret << endl;
	}
	return 0;
}
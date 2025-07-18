#include <iostream>

using namespace std;

int n, sum, idx, r, ret_top, ret_bottom;

int main()
{
	cin >> n;
	while (true)
	{
		if (n <= sum)
		{
			r = sum - n;
			if (idx & 1)
			{
				// È¦¼ö
				ret_top = 1 + (r);
				ret_bottom = idx - (r);
			}
			else
			{
				// Â¦¼ö
				ret_top = idx - (r);
				ret_bottom = 1 + (r);
			}
			break;
		}
		++idx;
		sum += idx;
	}
	cout << ret_top << '/' << ret_bottom;
	return 0;
}
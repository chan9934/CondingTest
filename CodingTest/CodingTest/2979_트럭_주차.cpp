#include <iostream>

using namespace std;


int A, B, C;
int cnt[100];

int main()
{

	cin >> A >> B >> C;

	for (int i = 0; i < 3; ++i)
	{
		int s_t, e_t;
		cin >> s_t >> e_t;
		for (int j = s_t; j < e_t; ++j)
		{
			++cnt[j];
		}
	}
	int sum = 0;
	for (int element : cnt)
	{
		if (element == 1)
		{
			sum += A;
		}
		else if (element == 2)
		{
			sum += 2 * B;
		}
		else if (element == 3)
		{
			sum += 3 * C;
		}
	}
	cout << sum;
	return 0;
}
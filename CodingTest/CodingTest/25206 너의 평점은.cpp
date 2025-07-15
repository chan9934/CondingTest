#include <iostream>

using namespace std;

float n, a, b;
string title, score;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	for(int i = 0; i < 20; ++i)
	{
		cin >> title >> n >> score;
		if (score == "P")
			continue;
		float temp = 4 - (score[0] - 'A');
		if (temp < 0)
		{
			temp = 0;
		}
		else
		{
			if (score[1] == '+')
				temp += 0.5;
		}
		a += (n * temp);
		b += n;
	}
	cout.precision(6);
	cout << fixed;
	cout << a / b << "\n";
	return 0;
}
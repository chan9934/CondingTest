#include <iostream>

using namespace std;

int x, ret;

void go(int current, int sum, int num)
{
	//cout << "current : " << current << " sum : " << sum << " num : " << num << "\n";
	if (current < 1)
		return;
	if (current == x)
	{
		ret = 1;
		return;
	}
	if (sum > x)
		return;
	if (sum == x)
	{
		ret = num;
		return;
	}

	go(current / 2, sum + current / 2, num + 1);
	go(current / 2, sum, num);

}

int main()
{
	cin >> x;
	go(64, 0, 0);
	cout << ret;
	return 0;
}
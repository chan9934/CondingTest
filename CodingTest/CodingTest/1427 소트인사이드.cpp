#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

ll n;
vector<int>numbers;

int main()
{
	cin >> n;
	while (n > 0)
	{
		numbers.push_back(n % 10);
		n /= 10;
	}
	sort(numbers.begin(), numbers.end(),
		[](int first, int second)
		{
			return first > second;
		});
	for (const int element : numbers)
	{
		cout << element;
	}
	cout << "\n";
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int avr, mid, n;
vector<int >v;

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		cin >> n;
		v.push_back(n);
		avr += n;
	}
	sort(v.begin(), v.end());
	cout << avr / 5 << "\n" << v[2] << "\n";
	return 0;
}
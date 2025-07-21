#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a1, a2, a3;

int main()
{
	while (cin >> a1 >> a2 >> a3)
	{
		vector<int>v;
		v.push_back(a1);
		v.push_back(a2);
		v.push_back(a3);
		sort(v.begin(), v.end());
		if (v[0] == 0)break;
		if (v[0] + v[1] <= v[2]) cout << "Invalid" << "\n";
		else if (v[0] == v[1] && v[1] == v[2])cout << "Equilateral" << "\n";
		else if (v[0] != v[1] && v[1] != v[2] && v[0] != v[2]) cout << "Scalene" << "\n";
		else  cout << "Isosceles" << "\n";
	}
	return 0;
}
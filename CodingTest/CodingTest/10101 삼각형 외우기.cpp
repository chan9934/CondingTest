#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
int temp;

int main()
{
	for(int i = 0; i < 3; ++i)
	{
		cin >> temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());
	
	if(a[0] + a[1] +a[2] != 180)cout << "Error" << "\n";
	else if(a[0] == 60 && a[1] == 60 && a[2] ==60)cout << "Equilateral" << "\n";
	else if (a[0] != a[1] && a[0] != a[2] && a[1] != a[2])cout << "Scalene" << "\n";
	else cout << "Isosceles" << "\n";
	return 0;
}
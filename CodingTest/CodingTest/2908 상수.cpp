#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string a, b;
int c, d;
int main()
{
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	c = stoi(a);
	d = stoi(b);
	cout << max(c, d) << "\n";
	return 0;
}
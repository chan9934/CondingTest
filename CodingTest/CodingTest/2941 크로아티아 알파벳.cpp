#include <iostream>
#include <algorithm>

using namespace std;

int ret;
string s;

void substract(const string& str)
{
	while (true)
	{
		size_t temp = s.find(str);
		if (temp == string::npos)
		{
			return;
		};
		s.replace(s.begin() + temp, s.begin() + temp + size(str), "#");
	}
}

int main()
{
	cin >> s;

	substract("c=");
	substract("c-");
	substract("dz=");
	substract("d-");
	substract("lj");
	substract("nj");
	substract("s=");
	substract("z=");

	cout << size(s) << "\n";
	return 0;
}

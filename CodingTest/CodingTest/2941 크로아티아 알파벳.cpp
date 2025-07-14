#include <iostream>

using namespace std;

string s;
int ret;

void removestr(const string& str, size_t& offset)
{
	size_t temp = s.find(str, offset);
	if (temp != string::npos)
	{
		offset = temp + 2;
		ret -= (str.size() - 1);
	}
}
void check(string str)
{
	ret = str.size();
	size_t offset = 0;
	while (true)
	{
		int temp = ret;
		removestr("c=", offset);
		removestr("c-", offset);
		removestr("dz=", offset);
		removestr("d-", offset);
		removestr("lj", offset);
		removestr("nj", offset);
		removestr("s=", offset);
		removestr("z=", offset);
		if (temp == ret)
			return;
	}
}
int main()
{
	cin >> s;
	check(s);
	cout << ret << "\n";
	return 0;
}
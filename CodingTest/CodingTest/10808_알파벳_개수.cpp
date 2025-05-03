#include <iostream>
#include <map>

using namespace std;
string str;
int cnt[26];

int main()
{
	cin >> str;
	for (char chr : str)
	{
		++cnt[int(chr) - 'a'];
	}
	for (int element : cnt)
	{
		cout << element << " ";
	}

	return 0;

}
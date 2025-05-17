#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define END "end"
#define PASS " is acceptable."
#define UNPASS " is not acceptable."

bool isVowel(char chr)
{
	if (chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u')
		return true;
	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	while (cin >> s)
	{
		if (s == END)
		{
			break;
		}
		int lcnt = 0, vcnt = 0;
		bool is_include_v = false;
		char prev;
		bool pass = true;

		for (size_t i = 0; i < size(s); ++i)
		{
			if (isVowel(s[i])) ++vcnt, lcnt = 0, is_include_v = true;
			else
				++lcnt, vcnt = 0;

			if (lcnt >= 3 || vcnt >= 3)
			{
				pass = false;
				break;
			}
			if (i != 0 && ((prev == s[i]) && (prev != 'e' && prev != 'o')))
			{
				pass = false;
				break;
			}
			prev = s[i];
		}
		if(is_include_v == false)
			pass = false;

		s = '<' + s + '>';
		if (pass)
		{
			cout << s << PASS << "\n";
		}
		else
		{
			cout << s << UNPASS << "\n";
		}

	}
	return 0;
}
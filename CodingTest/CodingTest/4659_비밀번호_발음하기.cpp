#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define END "end"
#define PASS " is acceptable."
#define UNPASS " is not acceptable."

vector<char> vowel= { 'a','e','i','o','u' };

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
		bool num_vowel = false;
		int current_sequence = 0;
		bool before_vowel = false;
		bool pass = true;

		for (size_t i = 0; i < size(s); ++i)
		{
			if (vowel.end() != find(vowel.begin(), vowel.end(), s[i]))
			{
				num_vowel = true;
				if (i != 0)
				{
					if (!before_vowel)
					{
						current_sequence = 1;
					}
					else
					{
						++current_sequence;
					}
				}
				else
					++current_sequence;
				before_vowel = true;
			}
			else
			{
				if (i != 0)
				{
					if (before_vowel)
					{
						current_sequence = 1;
					}
					else
					{
						++current_sequence;
					}
				}
				else
					++current_sequence;
				before_vowel = false;
			}
			if( i == 0)
			{
				continue;
			}

			if (current_sequence >= 3)
			{
				pass = false;
				break;
			}
			if (s[i - 1] == s[i])
			{
				if (s[i] != 'e' && s[i] != 'o')
				{
					pass = false;
					break;
				}
			}
		}
		if(num_vowel == false)
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
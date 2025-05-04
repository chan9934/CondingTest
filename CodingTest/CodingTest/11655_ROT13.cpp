#include <iostream>
#include <string>

using namespace std;

string input_str;

void Adjust_ROT13()
{
	for (char& input_chr : input_str)
	{
		if (int('a') <= int(input_chr) && int(input_chr) <= int('z'))
		{
			// 소문자 체크
			input_chr = (((int(input_chr) + 13) - int('a')) % 26) + int('a');
		}
		else if (int('A') <= int(input_chr) && int(input_chr) <= int('Z'))
		{
			// 대문자 체크
			input_chr = (((int(input_chr) + 13) - int('A')) % 26) + int('A');
		}
	}
}

int main()
{
	getline(cin, input_str);
	Adjust_ROT13();
	cout << input_str;
	return 0;
}

#include "CodingTest.h"

vector<string> split(const string& input, const string& delimiter)
{
	vector<string> return_string;
	auto start = 0;
	auto end = input.find(delimiter);

	while (end != string::npos)
	{
		return_string.emplace_back(input.substr(start, end - start));
		start = end + delimiter.size();
		end = input.find(delimiter, start);
	}
	return_string.emplace_back(input.substr(start));
	return return_string;
}

int main()
{
	string test = "apple, banana, grape, orange";
	vector<string> tests = split(test, ", ");
	for (auto teststrgin : tests)
	{
		cout << teststrgin << " ";
	}
	cout << endl;
	return 0;
}
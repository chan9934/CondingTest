#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int n, m;
string input_str;
map < string, vector<string>>wear_type;

void split_str(const string& str, char delimeter, string& left_str, string& right_str)
{
	auto find_delimeter = str.find(delimeter);
	left_str = str.substr(0, find_delimeter);
	right_str = str.substr(find_delimeter +1 );

}

void combi(int num, int r, vector<int>&ret_indeices, int start_index)
{
	if (ret_indeices.size() == r)
	{
		return;
	}

	for (int i = start_index + 1; i < num; ++i)
	{
		ret_indeices.emplace_back(i);
		combi(num, r, ret_indeices, i);
		ret_indeices.pop_back();
	}
}

int calculate()
{
	int result = 0;
	if (!wear_type.empty())
	{
		vector<int> indeices;
		int num = wear_type.size();
		for (int i = 1; i <= num; ++i)
		{
			combi(num, i, indeices, -1);

			for (int j = 0; j < indeices.size(); ++j)
			{
				indeices[j]
			}
		}
	}
	return result;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> m;
		for (int j = 0; j < m; ++j)
		{
			string input_str;
			getline(cin, input_str);

			string left_str;
			string right_str;
			wear_type[right_str].emplace_back(left_str);
		}

	}

}
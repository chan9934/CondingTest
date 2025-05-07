#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
string input_str;
map < string, vector<string>>wear_type_map;
vector<string>wear_type_vec;

void split_str(const string& str, char delimeter, string& left_str, string& right_str)
{
	auto find_delimeter = str.find(delimeter);
	left_str = str.substr(0, find_delimeter);
	right_str = str.substr(find_delimeter + 1);

}

int combi(int num, int r, vector<int>& ret_indeices, int start_index)
{
	static int result_value = 0;
	if (start_index == -1)
	{
		cout << "start_index start combi " << "\n";
		result_value = 0;
	}
	if ((int)ret_indeices.size() == r)
	{
		for (int index : ret_indeices)
		{
			if ((int)wear_type_vec.size() - 1 >= index)
			{
				string wear_type_str = wear_type_vec[index];

				auto wear_names = wear_type_map.find(wear_type_str);
				if (wear_names == wear_type_map.end())
				{
					cout << "calculate error" << "\n";
					return 0;
				}
				return (int)wear_names->second.size();
			}
			else
			{
				cout << "calculate error" << "\n";
				return 0;
			}
		}
		return 0;
	}

	for (int i = start_index + 1; i < num; ++i)
	{
		ret_indeices.emplace_back(i);
		int test = combi(num, r, ret_indeices, i);
		result_value += test;
		cout << "test : " << test << " result_value : " << result_value << endl;
		ret_indeices.pop_back();
	}
	return result_value;
}

int calculate()
{
	int result = 0;
	if (!wear_type_map.empty())
	{
		int num = (int)wear_type_map.size();
		for (int i = 1; i <= num; ++i)
		{
			vector<int> indeices;
			int result_value = combi(num, i, indeices, -1);
			result += result_value;
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
		wear_type_map.clear();
		wear_type_vec.clear();
		for (int j = 0; j < m; ++j)
		{
			string input_str;
			cin.ignore();
			getline(cin, input_str);

			string left_str, right_str;
			split_str(input_str, ' ', left_str, right_str);
			wear_type_map[right_str].emplace_back(left_str);
			auto find_vec = find(wear_type_vec.begin(), wear_type_vec.end(), right_str);
			if (find_vec == wear_type_vec.end())
			{
				wear_type_vec.emplace_back(right_str);
			}
		}
		cout << calculate() << "\n";

	}
	return 0;

}
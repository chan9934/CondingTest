#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n = 9, r = 7;
vector<int>input_vec;

void vec_print(const vector<int>& vec)
{
	for (int i = 0; i < r; ++i)
	{
		cout << vec[i] << endl;
	}

}
bool vec_sum(const vector<int>& Indexes)
{
	int sum = 0;
	for (int Index : Indexes)
	{
		sum += input_vec[Index];
	}
	if (sum == 100)
		return true;
	return false;
}
bool func_Combi( vector<int>& ret_combi, int depth)
{
	if (!ret_combi.empty() && ret_combi.size() == r)
	{
		if (vec_sum(ret_combi))
		{
			return true;
		}
		return false;
	}

	for (int i = depth + 1; i < n; ++i)
	{
		ret_combi.emplace_back(i);
		if (func_Combi(ret_combi, depth + 1))
		{
			return true;
		}
		ret_combi.pop_back();
	}
	return false;
}

int main()
{
	for (int i = 0; i < n; ++i)
	{
		int value;
		cin >> value;
		input_vec.push_back(value);
	}
	vector<int> combi_Indexes;
	func_Combi(combi_Indexes, -1);
	if(!combi_Indexes.empty())
	{
		vector<int>ret_vec;
		for (int Index : combi_Indexes)
		{
			ret_vec.emplace_back(input_vec[Index]);
		}
		sort(ret_vec.begin(), ret_vec.end());
		vec_print(ret_vec);
	}

	return 0;
}
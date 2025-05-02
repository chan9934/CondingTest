#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n = 9, r = 7;
vector<int>intput_vec, ret_vec;

void vec_print(const vector<int>& vec)
{
	for (int i = 0; i < r; ++i)
	{
		cout << vec[i] << endl;
	}

}
bool vec_sum(const vector<int>& vec)
{
	int sum = 0;
	for (int i = 0; i < r; ++i)
	{
		sum += vec[i];
	}
	if (sum == 100)
		return true;
	return false;
}
bool func_Permu( int depth)
{
	if (depth == r)
	{
		if (vec_sum(intput_vec))
		{

			ret_vec = intput_vec;
			return true;
		}
		return false;
	}

	for (int i = depth; i < n; ++i)
	{
		swap(intput_vec[i], intput_vec[depth]);
		if (func_Permu(depth + 1))
		{
			return true;
		}
		swap(intput_vec[i], intput_vec[depth]);
	}
	return false;
}

int main()
{
	for (int i = 0; i < n; ++i)
	{
		int value;
		cin >> value;
		intput_vec.push_back(value);
	}
	func_Permu(0);
	if(!ret_vec.empty())
	{
		ret_vec.resize(r);
		sort(ret_vec.begin(), ret_vec.end());
		vec_print(ret_vec);
	}

	return 0;
}
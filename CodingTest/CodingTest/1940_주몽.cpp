#include <iostream>
#include <vector>
using namespace std;

int n, ret_cnt;
long long m;
vector<int> v;


void func_combi(int startindex, vector<int>& ret_index)
{
	if (size(ret_index) == 2)
	{
		if ((long long)(v[ret_index[0]] + v[ret_index[1]]) == m)
			ret_cnt++;
		return;
	}

	for (int i = startindex + 1; i < n; ++i)
	{
		ret_index.emplace_back(i);
		func_combi(i, ret_index);
		ret_index.pop_back();
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int number;
		cin >> number;
		if (number >= m)
			continue;
		v.emplace_back(number);
	}
	vector<int> combi_index;
	func_combi(-1, combi_index);
	cout << ret_cnt;
	return 0;
}
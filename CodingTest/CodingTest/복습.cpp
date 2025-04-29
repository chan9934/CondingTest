#include "CodingTest.h"
vector<int> vec = { 1,2,3,4,5 };
int n = 5;
int r = 3;

void Func_Combination(vector<int>v, int s_i)
{
	if (v.size() == r)
	{
		Permutation::Print(v, r);
		return;
	}


	for (int i = s_i + 1; i < n; ++i)
	{
		v.push_back(i);
		Func_Combination(v, s_i + 1);
		v.pop_back();
	}
}
int main()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{

		}
	}
	return 0;
}
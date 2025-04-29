#include "CodingTest.h"
vector<int> vec = { 1,2,3,4,5 };
int n = 5;
int r = 3;

void Func_Permutation(int n, int r, int depth)
{
	if (r == depth)
	{
		Permutation::Print(vec, r);
		return;
	}
	for (int i = depth; i < n; ++i)
	{
		swap(vec[i], vec[depth]);
		Func_Permutation(n, r, depth + 1);
		swap(vec[i], vec[depth]);
	}
}
int main()
{

	Func_Permutation(5, 3, 0);
	return 0;
}
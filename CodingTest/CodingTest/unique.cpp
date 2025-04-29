#include "CodingTest.h"

vector<int> vec = { 3, 2, 1, 2, 2, 5,1, 5, 2,7,8, 2, 4, 9,0 };

int main()
{
	sort(vec.begin(), vec.end());

	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	Permutation::Print(vec, vec.size());

	return 0;
}
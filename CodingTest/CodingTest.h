#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

namespace Permutation
{
	void Print(int* arr, int r)
	{
		for (int i = 0; i < r; ++i)
		{
			cout << arr[i] << " ";
		}

		cout << endl;
	}
	void Print(const vector<int>& vec, int r)
	{
		for (int i = 0; i < r; ++i)
		{
			cout << vec[i] << " ";
		}
		cout << endl;
	}
}
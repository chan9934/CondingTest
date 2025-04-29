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
	
int arr[] = { 1, 2, 3 };
int n = 3;
int r = 3;

void Permutation(int n, int r, int d)
{
	if (r == d)
	{
		for (int i = 0; i < r; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << endl;

		return;
	}

	for (int i = d; i < n; ++i)
	{
		swap(arr[i], arr[d]);
		Permutation(n, r, d + 1);
		swap(arr[i], arr[d]);
	}
}


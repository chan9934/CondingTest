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

int main()
{
	int arr1[] = { 1,2,3 };
	int arr2[] = { 2,1,3 };

	vector<int> v = { 1, 2, 3, 100, 200 };

	do
	{
		for (auto E : arr2)
		{
			cout << E << " ";
		}
		cout << endl;
	} while (next_permutation(&arr2[0], &arr2[3]));
	cout << "test" << endl;
	for (auto E : arr2)
	{
		cout << E << " ";
	}
}
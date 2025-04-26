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

int n = 5;
int r = 3;
vector<int>V = { 1,2,3,4,5 };

void Combi(int Start, vector<int>& B)
{
	if (B.size() == r)
		return;

	for (int i = Start + 1; i < n; ++i)
	{
		B.push_back(i);
		Combi(i, B);
		B.pop_back();
	}
	return;
}

int main()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			for (int k = j+ 1; k < n; ++k)
			{

				cout << i << " " << j << " " << k << '\n';
			}
		}
	}
	return 0;
}
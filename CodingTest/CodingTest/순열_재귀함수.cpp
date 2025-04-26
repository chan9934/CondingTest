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

vector<int> V = { 1,2,3,4 };

void Function(int n, int r, int depth)
{
	if (r == depth)
	{
		for (int i = 0; i < r; i++) {
			cout << V[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = depth; i < n; ++i)
	{
		swap(V[i], V[depth]);
		Function(n, r, depth + 1);
		swap(V[i], V[depth]);
	}
}

int main()
{
	Function(4, 2, 0);

}
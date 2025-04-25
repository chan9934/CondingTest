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

int Fac(int n)
{
	if (n == 1 || n == 0) return 1;

	cout << n << endl;
	return n * Fac(n - 1);
}

int Fib(int n)
{
	cout << n << endl;
	if (n == 1 || n == 0) return n;
	return Fib(n - 1) + Fib(n - 2);
}

int main()
{
	int n;
	cin >> n;


	printf("return : %d", Fib(n));
	return 0;
}
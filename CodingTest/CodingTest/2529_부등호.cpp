#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
int k;
long long max_ret, min_ret;
string s_min_ret;

int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
char c[10];

bool check(int left, int right, char c)
{
	if (c == '<')
	{
		return left < right;
	}
	else if (c == '>')
	{
		return left > right;
	}
	return false;
}
string get_value()
{
	string s;
	for (int i = 0; i < k; ++i)
	{
		if (check(arr[i], arr[i + 1], c[i]))
		{
			s.push_back(arr[i] + '0');
		}
		else
			return string();
	}
	s.push_back(arr[k] + '0');
	return s;
}
void permutation(int depth)
{
	if (k + 1 == depth)
	{
		string s = get_value();
		if (string() != s)
		{

			long long value = stoll(s);
			max_ret = max(max_ret, value);
			min_ret = min(min_ret, value);
		}
	}

	for (int i = depth; i < 10; ++i)
	{
		swap(arr[i], arr[depth]);
		permutation(depth + 1);
		swap(arr[i], arr[depth]);
	}
}
int main()
{
	cin >> k;
	max_ret = 0;
	min_ret = 9999999999;
	for (int i = 0; i < k; ++i)
	{
		cin >> c[i];
	}
	permutation(0);
	int digits = pow(10, k);
	if (min_ret / digits == 0)
	{
		s_min_ret.push_back('0');
	}
	s_min_ret.append(to_string(min_ret));
	cout << max_ret << "\n" << s_min_ret;
	return 0;
}
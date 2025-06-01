#include <iostream>
#include <vector>

using namespace std;

int n, ret;
vector<char>v;

int get_value(int left, char mid, int right)
{

	if (mid == '+')
	{
		return left + right;
	}
	else if (mid == '-')
	{
		return left - right;
	}
	else if (mid == '*')
	{
		return left * right;
	}
	else if (mid == '/')
	{
		return left / right;
	}
	else
		return 0;
}
int combi(int count, int r, int startindex, vector<int>& indecies)
{
	if (indecies.size() == r)
	{
		/*int before_a = a[0];
		int before_c = a[0];
		for (int i = 1; i < n / 2; ++i)
		{
			char temp_c = c[i];
			int temp_a = a[i];
			if (indecies.end() == find(indecies.begin(), indecies.end(), i))
			{

			}
			else
			{

			}
		}*/
		int before_index = 0;
		for (auto element : indecies)
		{
			for (int i = before_index; i < element; ++i)
			{

			}
			before_index = element;

			int left = atoi(&v[element * 2]);
			int right = atoi(&v[element * 2 + 2]);
			char mid = v[element * 2 + 1];

			int temp = 0;
			if (mid == '+')
			{
				temp = left + right;
			}
			else if (mid == '-')
			{
				temp = left - right;
			}
			else if (mid == '*')
			{
				temp = left * right;
			}
			else if (mid == '/')
			{
				temp = left / right;
			}
			for(int i = temp_v.size(); i < element * 2 -1; ++i)
			{
				temp_v.push_back(v[i]);
			}
			temp_v.push_back('+');
			temp_v.push_back(temp + '0');
		}
		return 0;
	}
	for (int i = startindex + 1; i < count; ++i)
	{
		indecies.push_back(i);
		combi(count, r, i, indecies);
		indecies.pop_back();
	}
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		v.push_back(c);
	}

	ret = numeric_limits<int>::min();
	for (int i = 1; i <= n/2; ++i)
	{
		vector<int> indecies;
		ret = max( ret, combi(n / 2, i,-1, indecies));
	}
}
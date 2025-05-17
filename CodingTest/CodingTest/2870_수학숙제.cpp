#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s;
vector<string> ret;
vector<string> extract(string s)
{
	vector<string>ret;
	string temp;
	auto push = [&temp, &ret]()
		{
			if (!temp.empty())
			{
				// temp 가 채워져 있으면
				while (temp.size() != 1 && temp[0] == '0')
				{
					temp.erase(0, 1);
				}
				ret.push_back(temp);
				temp.clear();
			}
		};
	for (char c : s)
	{
		if (c < 'a' || c > 'z')
		{
			temp += c;
		}
		else
		{
			push();
		}
	}
	push();
	return ret;
}

bool comp(const string& a, const string& b)
{
	if (a == b)
		return false;
	if (a.size() == b.size())
	{
		for (size_t i = 0; i < a.size(); ++i)
		{
			if (a[i] != b[i])
			{
				return a[i] < b[i];
			}
		}
	}
	else
	{
		return a.size() < b.size();
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		vector<string>temp = extract(s);
		if (ret.empty())
		{
			ret = temp;
		}
		else
		{
			ret.insert(ret.end(), temp.begin(), temp.end());
		}
	}
	sort(ret.begin(), ret.end(), comp);
	for (string s : ret)
	{
		cout << s << "\n";
	}
	return 0;
}
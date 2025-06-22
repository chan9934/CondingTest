#include<iostream>
#include<vector>
#include<bitset>
#include<string>

using namespace std;

int n, k, ret, check;
vector<string >s;

int calcul()
{
	int num = 0;
	for (const string& element_1 : s)
	{
		bool success = true;
		for (char element_2 : element_1)
		{
			if (check & (1 << (element_2 - 'a')))continue;
			success = false;
			break;
		}
		if (success) ++num;
	}
	return num;
}
void extract(string& s)
{
	s.erase(s.begin(), s.begin() + 4);
	s.erase(s.end()-4, s.end());

}
void combi(vector<int>&indecies, int s_i)
{
	if (indecies.size() == k)
	{
		int temp = check;
		for (int index : indecies)
		{
			int bit = (1 << index);
			if (check & bit)
			{
				check = temp;
				return;
			}
			check |= bit;
		}
		ret = max(ret, calcul());
		check = temp;
		return;
	}

	for (int i = s_i + 1; i < 26; ++i)
	{
		indecies.push_back(i);
		combi(indecies, i);
		indecies.pop_back();
	}
}
int main()
{
	cin >> n >> k;
	ret = 0;
	if (k < 5)
	{
		cout << 0 << "\n";
		return 0;
	}
	k -= 5;
	check |= (1 << ('a' - 'a'));
	check |= (1 << ('n' - 'a'));
	check |= (1 << ('t' - 'a'));
	check |= (1 << ('i' - 'a'));
	check |= (1 << ('c' - 'a'));
	for (int i = 0; i < n; ++i)
	{
		string temp;
		cin >> temp;
		extract(temp);
		s.push_back(temp);
	}
	vector<int>indecies;
	combi(indecies, -1);

	cout << ret << "\n";
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n, c;
map<int, int>mp, mp_first;

vector<pair<int, int>> v;

bool cmp(pair<int, int> A, pair<int, int> B)
{
	if (A.second == B.second)
	{
		return mp_first[A.first] < mp_first[B.first];
	}
	return A.second > B.second;
}

int main()
{
	cin >> n >> c;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		int mp_value = ++mp[temp];
		if (mp_value == 1)
			mp_first[temp] = i;
	}
	for (auto element : mp)
	{
		v.push_back(element);
	}
	sort(v.begin(), v.end(), cmp);
	for (auto i : v) {
		for (int j = 0; j < i.second; j++) {
			cout << i.first << " ";
		}
	}
	return 0;
}
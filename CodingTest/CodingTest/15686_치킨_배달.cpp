#include <iostream>
#include <vector>

using namespace std;

int n, m, ret;

int a[54][54];
int visited[54][54];
vector<pair<int, int>>chikens;
vector<pair<int, int>>homes;

void combi(int s, vector<int>& indecies)
{
	if (indecies.size() == m)
	{
		int current = 0;
		for (auto home : homes)
		{
			int temp = 100;
			for (int index : indecies)
			{
				pair<int, int>chiken = chikens[index];
				temp = min(temp, abs(chiken.first - home.first) + abs(chiken.second - home.second));
			}
			current += temp;
		}
		ret = min(ret, current);
		return;
	}

	for (int i = s + 1; i < chikens.size(); ++i)
	{
		indecies.push_back(i);
		combi(i, indecies);
		indecies.pop_back();
	}
}
int main()
{
	cin >> n >> m;
	ret = 2 * n * 100;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
			if (a[i][j] == 2)
				chikens.push_back({ i, j });
			else if (a[i][j] == 1)
				homes.push_back({ i, j });
		}
	}
	vector<int> v;
	combi(-1, v);
	cout << ret;
}
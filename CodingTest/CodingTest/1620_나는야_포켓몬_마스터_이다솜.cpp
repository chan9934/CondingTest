#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int N, M;
map<string, int>dogam_strs;
map<int, string>dogam_numbers;
vector<string>rets;

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		string str;
		cin >> str;
		dogam_numbers[i] = str;
		dogam_strs[str] = i;
	}
	for (int i = 0; i < M; ++i)
	{
		string matter;
		cin >> matter;
		if (isdigit(matter[0]))
		{
			rets.emplace_back(dogam_numbers[stoi(matter)]);
		}
		else
		{
			rets.emplace_back(to_string(dogam_strs[matter]));
		}
	}

	for (string ret : rets)
	{
		cout << ret << endl;
	}
	return 0;
}
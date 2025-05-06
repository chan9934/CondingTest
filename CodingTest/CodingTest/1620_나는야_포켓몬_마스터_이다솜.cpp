#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int N, M;
map<string, int>dogam_strs;
vector<string>dogam;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	dogam.resize(N + 4);
	for (int i = 1; i <= N; ++i)
	{
		string str;
		cin >> str;
		dogam[i] = str;
		dogam_strs[str] = i;
	}
	for (int i = 0; i < M; ++i)
	{
		string matter;
		cin >> matter;
		int number = atoi(matter.c_str());
		if (number != 0)
		{
			cout << dogam[number] << "\n";
		}
		else
		{
			cout << dogam_strs[matter] << "\n";
		}
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ret_cnt;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		if (size(str) & 1)continue;

		{
			int A_cnt = 0;
			int B_cnt = 0;
			for (char chr : str)
			{
				if (chr == 'A')
					++A_cnt;
				else if (chr == 'B')
					++B_cnt;
			}
			if (A_cnt & 1 || B_cnt & 1)
				continue;

		}
		while (true)
		{
			if (str.empty())
				++ret_cnt;
			else if (str.size() == 1)
				break;

			auto find_index = str.find("AA");
			if (string::npos != find_index)
			{
				str.erase(find_index, 2);
				continue;
			}
			find_index = str.find("BB");
			if (string::npos != find_index)
			{
				str.erase(find_index, 2);
				continue;
			}
			break;
		}
	}
	cout << ret_cnt;
	return 0;
}
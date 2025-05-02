#include <iostream>
#include <map>

using namespace std;
string str;
map<int, int> alphabet_map;

int main()
{
	cin >> str;
	for (int i = int('a'); i <= int('z'); ++i)
	{
		alphabet_map.emplace(i, 0);
	}
	for (char chr : str)
	{
		auto iterator = alphabet_map.find(chr);
		++iterator->second;
	}
	for (auto alphabet : alphabet_map)
	{
		cout << alphabet.second << " ";
	}

	return 0;

}
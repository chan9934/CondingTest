#include <iostream>
#include <bitset>

using namespace std;

int n, k, mask;
string s;
int worlds[51];

int count(int mask)
{
	int cnt = 0;
	for (int world : worlds)
	{
		if (world && (world & mask) == world)cnt++;
	}
	return cnt;
}

int go(int index, int r, int mask)
{
	if (r < 0) return 0;
	if (index == 26) return count(mask);
	int ret = 0;
	int bit = 1 << index;
	if (!(mask & bit))
	{
		ret = max( ret, go(index + 1, r - 1, mask | bit));
	}
	ret = max(ret, go(index + 1, r, mask));

	return ret;
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		int world = 0;
		for (char c : s)
		{
			world |= (1 <<( c - 'a'));
		}
		worlds[i] = world;
		//cout << bitset<15>(world) << "\n";
	}
	mask |= (1 << ('a' - 'a'));
	mask |= (1 << ('n' - 'a'));
	mask |= (1 << ('t' - 'a'));
	mask |= (1 << ('i' - 'a'));
	mask |= (1 << ('c' - 'a'));
	cout << go(0, k - 5, mask) << "\n";
	return 0;
}
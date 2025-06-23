#include <iostream>
#include <bitset>

using namespace std;

int n, k;
int words[51];
string s;

void masking(int& mask, char c)
{
	mask |= (1 << (c - 'a'));
}
int calcul(int mask)
{
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if ((words[i] & mask) == words[i])
		{
			++cnt;
		}
	}
	return cnt;
}

int go(int index, int r, int mask)
{
	if (r <= 0 || index == 26)
	{
		return calcul(mask);
	}
	int ret = 0;
	if (!(mask & (1 << index)))
	{
		ret = go(index + 1, r - 1, mask | (1 << (index)));
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
		int word = 0;
		for (char c : s)
		{
			masking(word, c);
		}
		/*cout << bitset<26>(word) << "\n";
		for (int i = 25; i >= 0; --i)
		{
			cout << char(i + 'a');
		}
		cout << "\n";*/
		words[i] = word;
	}

	if (k < 5)
	{
		cout << 0 << "\n";
		return 0;
	}
	int mask = 0;
	masking(mask, 'a');
	masking(mask, 'n');
	masking(mask, 't');
	masking(mask, 'i');
	masking(mask, 'c');
	cout << go(0, k - 5, mask) << "\n";
	return 0;

}
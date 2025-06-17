#include <iostream>
#include <vector>

using namespace std;

char a[24][24];
char h[24][24];
int num_t, n, ret;

void print(const string& s)
{
	cout << s << "\n";
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << a[i][j];
		}
		cout <<  "\n";
	}
}
void go()
{
	bool next = false;
	for (int i = 0; i < n; ++i)
	{
		int t = 0;
		for (int j = 0; j < n; ++j)
		{
			if (a[i][j] == 'T')
				++t;
		}
		if (t > (n / 2))
		{
			next = true;
			for (int j = 0; j < n; ++j)
			{
				if (a[i][j] == 'T')
				{
					a[i][j] = 'H';
					--num_t;
				}
				else if (a[i][j] == 'H')
				{
					a[i][j] = 'T';
					++num_t;
				}
			}
		}
	}
	print("vertical");
	for (int i = 0; i < n; ++i)
	{
		int t = 0;
		for (int j = 0; j < n; ++j)
		{
			if (a[j][i] == 'T')
				++t;
		}
		if (t > (n / 2))
		{
			next = true;
			for (int j = 0; j < n; ++j)
			{
				if (a[j][i] == 'T')
				{
					a[j][i] = 'H';
					--num_t;
				}
				else if (a[j][i] == 'H')
				{
					a[j][i] = 'T';
					++num_t;
				}
			}
		}
	}
	print("horizental");
	if (num_t < 2)
		return;
	ret = min(ret, num_t);

	if (next)
		go();
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
			if (a[i][j] == 'T')
				++num_t;
		}
	}

	ret = num_t;
	go();
	cout << ret << "\n";
	return 0;
}
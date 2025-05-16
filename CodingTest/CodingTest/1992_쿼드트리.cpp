#include<iostream>

using namespace std;

int n;
char a[68][68];
string ret;

int dy[] = { 0, 0, 1, 1 };
int dx[] = { 0, 1, 0, 1 };

string go(int s_y, int s_x, int d)
{
	string r_s;
	for (int i = 0; i < 4; ++i)
	{
		int ny = s_y + dy[i] * d;
		int nx = s_x + dx[i] * d;
		if (d == 1)
		{
			r_s += a[ny][nx];
		}
		else
		{
			r_s += go(ny, nx, d / 2);
		}
	}
	if(r_s == "")
		cout << "ny : " << s_y << " nx : " << s_x << "\n";
	if (d == 1)
	{
		char chk = r_s[0];
		cout << "chk : " << chk << "\n";
		for (int i = 1; i < 4; ++i)
		{
			if (chk != r_s[i])
				return '(' + r_s + ')';
		}
		r_s = chk;
		return r_s;
	}
	if (r_s.size() != 4)
	{
		return '(' + r_s + ')';
	}
	else
	{
		return r_s;
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}
	cout << go(0, 0, n);

	return 0;
}
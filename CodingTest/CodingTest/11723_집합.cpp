#include <iostream>

using namespace std;


int m, s;

string oper;
int value;
void bit_add(int x)
{
	int index = x - 1;
	s |= (1 << index);
}
void bit_remove(int x)
{
	int index = x - 1;
	s &= ~(1 << index);
}
void bit_toggle(int x)
{
	int index = x - 1;
	s ^= (1 << index);
}
void bit_all()
{
	static int all_value = 0;
	if (all_value == 0)
	{
		for (int i = 0; i < 20; ++i)
		{
			all_value |= (1 << i);
		}
	}
	s = all_value;
}
void bit_empty()
{
	s = 0;
}
void bit_check(int x)
{
	int index = x - 1;
	if (s & (1 << index))
	{
		cout << 1 << "\n";
	}
	else
	{
		cout << 0 << "\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> oper;
		if (oper != "all" && oper != "empty")
		{
			cin >> value;
		}

		if (oper == "add")
		{
			bit_add(value);
		}
		else if (oper == "remove")
		{
			bit_remove(value);

		}
		else if (oper == "check")
		{
			bit_check(value);
		}
		else if (oper == "toggle")
		{
			bit_toggle(value);
		}
		else if (oper == "all")
		{
			bit_all();
		}
		else if (oper == "empty")
		{
			bit_empty();
		}
	}
	return 0;
}
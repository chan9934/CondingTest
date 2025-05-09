#include <iostream>
#include <vector>
using namespace std;

int Number;


int main()
{
	while (cin >> Number)
	{
		int Index = 1;
		int Remainder = 1;
		while (true)
		{
			if (Remainder % Number == 0)
			{
				break;
			}
			Remainder = ((Remainder * 10) % Number + 1) % Number;
			++Index;
		}

		cout << Index << "\n";
	}
	return 0;
}
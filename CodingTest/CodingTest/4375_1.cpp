#include <iostream>
#include <vector>
using namespace std;

int Number;


int main()
{
	while (cin >> Number)
	{
		int Index = 0;
		int Remainder = 1;
		int Cumsum = 0;
		while (true)
		{
			++Index;
			Cumsum += Remainder;
			if (Cumsum % Number == 0)
			{
				break;
			}
			Remainder = (Remainder * 10) % Number;
		}

		cout << Index << "\n";
	}
	return 0;
}
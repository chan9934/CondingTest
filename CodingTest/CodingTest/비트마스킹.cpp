#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	int a = 5; // 0101
	int b = 10; // 1010

	cout << bitset<8>(a + b) << "\n"; // 1111 
	cout << bitset<8>(a & b) << "\n"; // 0000
	cout << bitset<8>(a | b) << "\n"; // 1111
	cout << bitset<8>(1 << a) << "\n"; // 2^a
	cout << bitset<8>(2 >> 1) << "\n"; // (1/2)^b
	cout << bitset<8>(a ^ b) << "\n"; // 1111
	cout << bitset<8>(~a) << "\n"; // 11111010 ~a = -(a + 1) -> -a = ~a + 1
	cout << bitset<8>(a &= ~(1 << 2)); // 0001 
}
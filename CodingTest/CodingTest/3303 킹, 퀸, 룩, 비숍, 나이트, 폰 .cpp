#include<iostream>

#define KING 1
#define QUEEN 1
#define ROOK 2
#define BISHOP 2
#define KNIGHT 2
#define PAWN 8

int k, q, r, b, n, p;

using namespace std;

int main()
{
	cin >> k >> q >> r >> b >> n >> p;
	cout << KING - k << " " << QUEEN - q << " " << ROOK - r << " " << BISHOP - b << " " << KNIGHT - n << " " << PAWN - p << endl;
	return 0;
}
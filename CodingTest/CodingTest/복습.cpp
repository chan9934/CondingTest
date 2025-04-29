#include "CodingTest.h"
int arr[] = { 1, 2, 3, 4, 5 };
int n = 5;
int r = 3;

void Func_Permutation()
{

}
int main()
{

	do
	{
		Permutation::Print(arr, r);
	} while (next_permutation(&arr[0], &arr[n]));
	
	return 0;
}
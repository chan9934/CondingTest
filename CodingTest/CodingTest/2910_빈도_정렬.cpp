#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct S_V
{
	int value;
	int Num = 1;

	S_V(int _value)
	{
		value = _value;
	}
	~S_V()
	{

	}
	bool operator==(const S_V& other)
	{
		if (value == other.value)
		{
			++Num;
			return true;
		}
		else
		{
			return false;
		}
	}
};
int n, c;
vector<S_V>vec;

int main()
{
	cin >> n >> c;

	int temp = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		S_V new_sv = S_V(temp);
		if (vec.end() == find(vec.begin(), vec.end(), new_sv))
			vec.push_back(new_sv);
	}
	stable_sort(vec.begin(), vec.end(),
		[](const S_V& A, const S_V& B)
		{
			return A.Num > B.Num;
		}
	);
	for (S_V v : vec)
	{
		for (int i = 0; i < v.Num; ++i)
		{
			cout << v.value << " ";
		}
	}
	return 0;
}
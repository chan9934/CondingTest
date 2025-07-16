#include <iostream>
#include <map>

using namespace std;

string subject, score;
float hakjeam, h_sum, s_sum;
map<string, float> m = {
	{"A+", 4.5},
	{"A0", 4.0},
	{"B+", 3.5},
	{"B0", 3.0},
	{"C+", 2.5},
	{"C0", 2.0},
	{"D+", 1.5},
	{"D0", 1.0},
	{"F", 0.0}
};

int main()
{
	for(int i = 0 ; i < 20; ++i)
	{
		cin >> subject >> hakjeam >> score;
		if (score == "P")continue;
		h_sum += hakjeam * m[score];
		s_sum += hakjeam;
	}
	cout.precision(6);
	cout << fixed << h_sum / s_sum << "\n";
	return 0;
}
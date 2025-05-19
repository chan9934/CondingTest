#include <iostream>
#include <string>
#define time ttt
using namespace std;

int n, t, t_a, t_b;
string time, s_t, e_t, a_time, b_time;

void split(string s, int& minutes, int& seconds)
{
	minutes = stoi(s.substr(0, 2));
	seconds = stoi(s.substr(3));
}
void apply_time(string& winner_time)
{
	int s_minutes, s_seconds, e_minutes, e_seconds, winner_minutes, winner_seconds;
	split(s_t, s_minutes, s_seconds);
	split(e_t, e_minutes, e_seconds);
	split(winner_time, winner_minutes, winner_seconds);
	int s_time = s_minutes * 60 + s_seconds;
	int e_time = e_minutes * 60 + e_seconds;
	int cal_time = e_time - s_time;
	winner_seconds += cal_time % 60;
	winner_minutes += cal_time / 60;
	if (winner_seconds >= 60)
	{
		winner_seconds -= 60;
		++winner_minutes;
	}
	char temp_minutes[3];
	char temp_seconds[3];
	snprintf(temp_minutes, sizeof(temp_minutes), "%02d", winner_minutes);
	snprintf(temp_seconds, sizeof(temp_seconds), "%02d", winner_seconds);
	winner_time = string(temp_minutes) + ':' + string(temp_seconds);
}
void cal(int& winner_team, int loser_team, string& winner_time)
{
	if (winner_team == loser_team)
	{
		s_t = time;
	}
	++winner_team;
	if (winner_team == loser_team)
	{
		e_t = time;
		apply_time(winner_time);
	}
}
int main()
{
	a_time = "00:00";
	b_time = "00:00";
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> t >> time;
		if (t == 1)
		{
			cal(t_a, t_b, b_time);
		}
		else
		{
			cal(t_b, t_a, a_time);
		}
	}
	e_t = "48:00";
	if (t_a > t_b)
		apply_time(a_time);
	else if(t_b > t_a)
		apply_time(b_time);
	cout << a_time << "\n" << b_time;
	return 0;
}
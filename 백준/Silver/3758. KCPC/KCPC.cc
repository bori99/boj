#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int T, num_team, num_pro, your_team, num_log;

struct 
{
	int score;
	int solve_num;
	int last_time;
	int team_idx;
	int problem[101];
} typedef Team_info;

bool my_sort(Team_info x, Team_info y)
{
	if (x.score != y.score) return x.score > y.score;
	if (x.solve_num != y.solve_num) return x.solve_num < y.solve_num;
	return x.last_time < y.last_time;
}

void Decide_Ans(Team_info team_info[])
{
	vector<Team_info> team;
	for (int i = 1; i <= num_team; i++) team.push_back({ team_info[i] });
	sort(team.begin(), team.end(), my_sort);
	for (int i = 0; i < team.size(); i++)
		if (team[i].team_idx == your_team)
		{
			cout << i + 1 << "\n";
			return;
		}
}

void Input()
{
	cin >> T;
	while (T--)
	{
		Team_info team_info[101];
		int team_id, pro_idx, point;

		cin >> num_team >> num_pro >> your_team >> num_log;

		for (int i = 1; i <= num_team; i++)
		{
			team_info[i].last_time = team_info[i].score = team_info[i].solve_num = 0;
			team_info[i].team_idx = i;

			for (int j = 1; j <= num_pro; j++)
			{
				team_info[i].problem[j] = 0;
			}
		}

		for (int i = 0; i < num_log; i++)
		{
			cin >> team_id >> pro_idx >> point;

			team_info[team_id].last_time = i + 1;

			if (team_info[team_id].problem[pro_idx] < point)
			{
				team_info[team_id].score += (point - team_info[team_id].problem[pro_idx]);
				team_info[team_id].problem[pro_idx] = point;
			}
			team_info[team_id].solve_num++;
		}
		Decide_Ans(team_info);
	}
}

int main()
{
	Input();

}
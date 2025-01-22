#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int N, Ans;
string Str[100], First;
int First_Asci[30], Next_Asci[30];

void Initialize()
{
	for (int i = 0; i < 26; i++) Next_Asci[i] = 0;
}

void Input()
{
	cin >> N >> First;
	for (int k = 0; k < First.size(); k++) First_Asci[First[k] - 'A']++;
	for (int i = 0; i < N - 1; i++) cin >> Str[i];
}

void Decide_Ans()
{
	for (int i = 0; i < N - 1; i++)
	{
		Initialize();
		int Dif_cnt = 0;

		for (int j = 0; j < Str[i].size(); j++)
		{
			Next_Asci[Str[i][j] - 'A']++;
		}
		for (int i = 0; i < 26; i++)Dif_cnt += (abs(Next_Asci[i] - First_Asci[i]));
		
		if (Dif_cnt <= 1) Ans++;
		else if (Dif_cnt == 2)
		{
			bool can = true;
			int abs_num = abs((int)First.size() - (int)Str[i].size());
			for (int i = 0; i < 26; i++)
			{
				int temp = abs(Next_Asci[i] - First_Asci[i]);
				if (temp >= 2)
				{
					can = false; break;
				}
			}
			
			if (can && abs_num <2)Ans++;
		}
	}
	cout << Ans;
}

int main()
{
	Input();
	Decide_Ans();
}
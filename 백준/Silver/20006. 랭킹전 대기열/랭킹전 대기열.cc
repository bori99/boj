#include<iostream>
#include<string>
#include<queue>
#include<unordered_set>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int p, m;
/* 구조체 안에 벡터를 따로 두어서 미리 값들을 모아놓고 이들을 my sort로 사전순 정렬을 통해 해결함.
우선 my sort가 헷갈렸는데, 해당하는 조건에만 일치하게 로직 넣어주면 해결한 거 인지하고 넘어가기*/
struct Room
{
	int level;
	int people;
	vector<pair<int, string>> info;
};

vector<Room> room;

bool My_sort(pair<int, string> x , pair<int, string> y)
{
	return x.second < y.second;
}

bool Is_enter(int num,string name)
{
	bool can = false;
	for (int i = 0; i < room.size(); i++)
	{
		int criteria = room[i].level, people_num = room[i].people;
		if (criteria - 10 <= num && criteria + 10 >= num && people_num < m)
		{
			can = true; room[i].people++;
			room[i].info.push_back({ num,name });
			break;
		}
	}
	return can;
}

void Assign_room(int level,string name)
{
	room.push_back({ level,1 });
	room[room.size() - 1].info.push_back({ level,name });
}

void Sorting_and_print()
{
	for (int i = 0; i < room.size(); i++)
	{
		sort(room[i].info.begin(), room[i].info.end(), My_sort);
	}

	for (int i = 0; i < room.size(); i++)
	{
		if (room[i].people != m) cout << "Waiting!" << "\n";
		else cout << "Started!" << "\n";
		for (int j = 0; j < room[i].info.size(); j++)
		{
			cout << room[i].info[j].first << " " << room[i].info[j].second << "\n";
		}
	}
}

void Input()
{
	cin >> p >> m;
	int level; string name;
	while (p--)
	{
		cin >> level >> name;
		bool enter = Is_enter(level,name);
		if (enter) continue;
		else Assign_room(level,name);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	Input();
	Sorting_and_print();
}

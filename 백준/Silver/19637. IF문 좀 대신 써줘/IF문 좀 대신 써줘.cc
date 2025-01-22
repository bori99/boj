#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int N, M, idx;
vector<pair<string, int>> name_and_num;

int Decide_Ans(int num)
{
	int left = 0, right = N-1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (name_and_num[mid].second < num) left = mid + 1;
		else
		{
			if (mid == 0 || name_and_num[mid - 1].second < num) return mid;
			right = mid - 1;
		}
	}
}

void Input()
{
	cin >> N >> M;
	name_and_num.resize(N);

	for (int i = 0; i < N; i++)	cin >> name_and_num[i].first >> name_and_num[i].second;

	int temp, idx;
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		idx = Decide_Ans(temp);
		cout << name_and_num[idx].first << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	Input();
}
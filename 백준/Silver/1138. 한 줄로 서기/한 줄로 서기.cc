#include<iostream>
#include<string>
#include<queue>
#include<unordered_set>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int N, M, Arr[15];
bool Is_in[15];

void Action(int num, int sequence)
{
	int idx = 1;
	while (1)
	{
		if (num == 0)
		{
			if (Is_in[idx] == false) break;
			else idx++;
		}
		else
		{
			if (Is_in[idx])idx++;
			else
			{
				idx++; num--;
			}
		}
	}
	Arr[idx] = sequence; Is_in[idx] = true;
}

void Print()
{
	for (int i = 1; i <= M; i++) cout << Arr[i] << " ";
}

void Input()
{
	int temp, idx = 1;
	cin >> N; M = N;
	while (N--)
	{
		cin >> temp;
		Action(temp,idx++);
	}
	Print();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	Input();
}
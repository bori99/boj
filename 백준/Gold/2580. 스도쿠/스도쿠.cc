#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int board[10][10];
int Empty;
vector<pair<int, int>> pos;

bool Row(int num, int x, int y)
{
	bool temp = true;
	for (int i = 0; i < 9; i++)
	{
		if (i == y) continue;
		if (board[x][i] == num)
		{
			temp = false; break;
		}
	}

	return temp;
}

bool Col(int num, int x, int y)
{
	bool temp = true;
	for (int i = 0; i < 9; i++)
	{
		if (i == x) continue;
		if (board[i][y] == num)
		{
			temp = false; break;
		}
	}

	return temp;
}

bool Square(int num, int x, int y)
{
	bool temp = true;
	int case_x = (x / 3) * 3;
	int case_y = (y / 3) * 3;

	for (int i = case_x; i < case_x + 3; i++)
	{
		for (int j = case_y; j < case_y + 3; j++)
		{
			if (i == x && j == y) continue;

			if (num == board[i][j])
			{
				temp = false; break;
			}
		}
	}
	return temp;
}

bool IsCan(int num, int x, int y)
{
	bool r = Row(num, x, y), c = Col(num, x, y), s = Square(num, x, y);
	return (r && c && s);
}

bool Recur(int pos_cnt)
{
	if (pos.size() == pos_cnt)
	{
		return true;
	}

	int x = pos[pos_cnt].first;
	int y = pos[pos_cnt].second;

	for (int i = 1; i <= 9; i++)
	{
		
		if (IsCan(i,x,y))
		{
			board[x][y] = i;
			if (Recur(pos_cnt + 1)) return true;
		}
		board[x][y] = 0;
	}
	return false;
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
			{
				pos.push_back({ i,j });
			}
		}
	}

	Empty = pos.size();
	Recur(0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}
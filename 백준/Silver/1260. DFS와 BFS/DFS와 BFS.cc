#include<iostream>
#include<stack>
#include<queue>
using namespace std;

bool graph[1005][1005];
bool used[1005];
int node, edge, st;

stack<int> Stack;
queue<int> Queue;

void DSearch()
{
	if (Stack.empty()) return;

	cout << Stack.top() << " ";
	int temp = Stack.top();
	Stack.pop();

	for (int i = 1; i <= 1000; i++)
	{
		if (graph[temp][i] != 0 && used[i] != true)
		{
			Stack.push(i);
			used[i] = true;
			DSearch();
		}
	}
}

void BSearch()
{
	while (Queue.empty() == false)
	{
		cout << Queue.front() << " ";
		int temp = Queue.front();
		Queue.pop();

		for (int i = 1; i <= 1000; i++)
		{
			if (graph[temp][i] == true && used[i] == false)
			{
				Queue.push(i);
				used[i] = true;
			}
		}
	}
}

void Memorize()
{
	for (int i = 0; i < 1005; i++) used[i] = false;
}

int main()
{
	
	cin >> node >> edge >> st;

	int temp1, temp2;
	for (int i = 0; i < edge; i++)
	{
		cin >> temp1 >> temp2;
		graph[temp1][temp2] = true;
		graph[temp2][temp1] = true;
	}

	Stack.push(st);
	used[st] = true;
	DSearch();
	cout << "\n";

	Memorize();

	Queue.push(st);
	used[st] = true;
	BSearch();
}
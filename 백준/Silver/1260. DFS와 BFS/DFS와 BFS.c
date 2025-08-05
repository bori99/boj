#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

#define Max 1001 //문제에서 1000개의 노드가 가능
int visit[Max];
int graph[Max][Max];
int queue[Max];

void DFS(int N, int Start)
{
	printf("%d ", Start);
	visit[Start] = 1;

	for (int i = 1; i <= N; i++)
	{
		if (graph[Start][i] == 1 && visit[i] == 0)// 연결돼있고 방문x일떄
		{
			DFS(N, i); //재귀 이용
		}
	}
}

void BFS(int N, int Start)
{
	printf("%d ", Start);
	int pop;
	int front = -1, rear = -1;

	queue[++rear] = Start;
	visit[Start] = 1;

	while (front < rear)
	{
		pop = queue[++front];

		for (int i = 1; i <= N; i++)
		{
			if (visit[i] == 0 && graph[pop][i] == 1)
			{
				printf("%d ", i);
				visit[i] = 1;
				queue[++rear] = i;
			}
		}
	}

}
int main()
{
	int N, M, V;
	int a, b;
	scanf("%d %d %d", &N, &M, &V);
	
	//그래프의 연결과 방향성 부여
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	DFS(N, V);
	printf("\n");

	visit[Max];
	for (int i = 0; i < Max; i++)
	{
		visit[i] = 0;
	}
	BFS(N, V);
}
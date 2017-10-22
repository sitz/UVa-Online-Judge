#include <bits/stdc++.h>

using namespace std;

#define INF 99999999

static int N, S, E, M, K;
static int graph[501][2], p[501][2], Comm[1000][3], Exp[1000][3];

inline void ShortestPath()
{
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 2; j++)
			graph[i][j] = INF;
	graph[S][0] = 0;
	p[S][0] = -1;
	while (true)
	{
		int min = INF, node, state;
		for (int i = 1; i <= N; i++)
			for (int j = 0; j < 2; j++)
				if (graph[i][j] != -1 && graph[i][j] < min)
				{
					min = graph[i][j];
					node = i;
					state = j;
				}
		if (node == E)
		{
			int path[500], len = 0, t = E, ts = state, station = -1;
			bool useticket = (state == 1);
			while (t > 0)
			{
				path[len++] = t;
				int pn = p[t][ts] >> 1, ps = p[t][ts] & 1;
				if (useticket && ps == 0 && station == -1)
				{
					station = pn;
				}
				t = pn;
				ts = ps;
			}
			for (int i = len - 1; i >= 0; i--)
			{
				if (i != len - 1)
				{
					putchar(' ');
				}
				printf("%d", path[i]);
			}
			puts("");
			if (useticket)
			{
				printf("%d\n", station);
			}
			else
			{
				puts("Ticket Not Used");
			}
			printf("%d\n", min);
			break;
		}
		for (int i = 0; i < M; i++)
		{
			if (Comm[i][0] == node && graph[Comm[i][1]][state] > min + Comm[i][2])
			{
				graph[Comm[i][1]][state] = min + Comm[i][2];
				p[Comm[i][1]][state] = (node << 1) | state;
			}
			if (Comm[i][1] == node && graph[Comm[i][0]][state] > min + Comm[i][2])
			{
				graph[Comm[i][0]][state] = min + Comm[i][2];
				p[Comm[i][0]][state] = (node << 1) | state;
			}
		}
		if (state == 0)
		{
			for (int i = 0; i < K; i++)
			{
				if (Exp[i][0] == node && graph[Exp[i][1]][1] > min + Exp[i][2])
				{
					graph[Exp[i][1]][1] = min + Exp[i][2];
					p[Exp[i][1]][1] = (node << 1) | state;
				}
				if (Exp[i][1] == node && graph[Exp[i][0]][1] > min + Exp[i][2])
				{
					graph[Exp[i][0]][1] = min + Exp[i][2];
					p[Exp[i][0]][1] = (node << 1) | state;
				}
			}
		}
		graph[node][state] = -1;
	}
}

int main()
{
	int cases = 0;
	while (scanf("%d %d %d", &N, &S, &E) == 3)
	{
		if (cases++)
			puts("");
		scanf("%d", &M);
		for (int i = 0; i < M; i++)
			scanf("%d %d %d", &Comm[i][0], &Comm[i][1], &Comm[i][2]);
		scanf("%d", &K);
		for (int i = 0; i < K; i++)
			scanf("%d %d %d", &Exp[i][0], &Exp[i][1], &Exp[i][2]);
		ShortestPath();
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define MAXN 102

struct pp
{
	int u, v;
	int move;
};
queue<pp> Q;
struct ss
{
	int colour;
} node[MAXN];
struct xx
{
	int E[MAXN];
	int C[MAXN];
	int ind;
} edge[MAXN];
char Visit[MAXN][MAXN];
int N, Min;

int MoveFirst(int c1, int c2, int terget, int move)
{
	int i, x;
	pp dum;
	for (i = 0; i < edge[c1].ind; i++)
	{
		if (edge[c1].E[i] != c2 && edge[c1].C[i] == node[c2].colour)
		{
			x = edge[c1].E[i];
			if (!Visit[x][c2])
			{
				if (x == terget)
				{
					Min = move;
					return 1;
				}
				dum.u = x;
				dum.v = c2;
				dum.move = move;
				Q.push(dum);
				Visit[x][c2] = Visit[c2][x] = 1;
			}
		}
	}
	return 0;
}
int MoveSecond(int c1, int c2, int terget, int move)
{
	int i, x;
	pp dum;
	for (i = 0; i < edge[c2].ind; i++)
	{
		if (edge[c2].E[i] != c1 && edge[c2].C[i] == node[c1].colour)
		{
			x = edge[c2].E[i];
			if (!Visit[x][c1])
			{
				if (x == terget)
				{
					Min = move;
					return 1;
				}
				dum.u = c1;
				dum.v = x;
				dum.move = move;
				Q.push(dum);
				Visit[x][c1] = Visit[c1][x] = 1;
			}
		}
	}
	return 0;
}
void BFS(int c1, int c2, int terget)
{
	pp temp, dum;
	temp.u = c1;
	temp.v = c2;
	temp.move = 0;
	Visit[c1][c2] = Visit[c2][c1] = 1;
	Q.push(temp);
	while (!Q.empty())
	{
		dum = Q.front();
		Q.pop();
		if (!Min)
		{
			MoveFirst(dum.u, dum.v, terget, dum.move + 1);
			MoveSecond(dum.u, dum.v, terget, dum.move + 1);
		}
	}
}
void Cal(int c1, int c2, int terget)
{
	int i, j;
	Min = 0;
	BFS(c1, c2, terget);
	printf("%d\n", Min);
	Q.empty();
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			Visit[i][j] = Visit[j][i] = 0;
}

int main()
{
	int i, c1, c2, terget, edg, c, st, ed;
	while (scanf("%d%d%d%d%d", &N, &c1, &c2, &terget, &edg) == 5)
	{
		if (!N && !c1 && !c2 && !terget && !edg)
			break;
		for (i = 0; i < N; i++)
		{
			scanf("%d", &c);
			node[i + 1].colour = c;
			edge[i].ind = 0;
		}
		for (i = 0; i < edg; i++)
		{
			scanf("%d%d%d", &st, &ed, &c);
			edge[st].E[edge[st].ind] = ed;
			edge[st].C[edge[st].ind++] = c;
		}
		Cal(c1, c2, terget);
	}
	return 0;
}

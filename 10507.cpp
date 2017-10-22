#include <bits/stdc++.h>

using namespace std;

#define MAXN 28

struct ss
{
	char visit_times;
	char color;
	int year;
} V[MAXN];
char Wake[MAXN];
char Link[MAXN][MAXN];
int Q[MAXN], H, T, N;

void Push(int n)
{
	Q[H++] = n;
	H %= MAXN;
}
int Pop()
{
	int n;
	n = Q[T++];
	T %= MAXN;
	return n;
}
int IsEmpty()
{
	return H == T;
}
int BFS()
{
	int i, j, totalvisit = 0;
	int k;
	for (i = 0; i < 26; i++)
	{
		V[i].visit_times = 0;
		V[i].color = V[i].year = 0;
	}
	H = T = 0;
	for (i = 0; Wake[i]; i++)
	{
		j = Wake[i] - 'A';
		V[j].color = 1;
		V[j].visit_times = 3;
		Push(j);
		totalvisit++;
	}
	if (totalvisit == N)
	{
		return 0;
	}
	while (!IsEmpty())
	{
		k = Pop();
		for (i = 0; i < 26; i++)
		{
			if (Link[k][i] == 0 || V[i].color == 1)
			{
				continue;
			}
			V[i].visit_times++;
			if (V[i].year < V[k].year + 1)
			{
				V[i].year = V[k].year + 1;
			}
			if (V[i].visit_times == 3)
			{
				V[i].color = 1;
				Push(i);
				totalvisit++;
			}
			if (totalvisit == N)
			{
				return V[i].year;
			}
		}
	}
	return -1;
}
void Free()
{
	int i, j;
	for (i = 0; i < 26; i++)
		for (j = 0; j < 26; j++)
		{
			Link[i][j] = Link[j][i] = 0;
		}
}
int main()
{
	int i, edge, j, k;
	char link[5];
	while (scanf("%d", &N) == 1)
	{
		scanf("%d", &edge);
		scanf("%s", Wake);
		for (i = 0; i < edge; i++)
		{
			scanf("%s", link);
			j = link[0] - 'A';
			k = link[1] - 'A';
			Link[j][k] = Link[k][j] = 1;
		}
		k = BFS();
		if (k == -1)
		{
			printf("THIS BRAIN NEVER WAKES UP\n");
		}
		else
		{
			printf("WAKE UP IN, %d, YEARS\n", k);
		}
		Free();
	}
	return 0;
}

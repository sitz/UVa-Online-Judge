#include <bits/stdc++.h>

using namespace std;

#define MAXN 30
#define MAXM 110
#define MAXD 2000000
#define INF 1000000000
int s[2][MAXM], t[2][MAXM], w[MAXM], N, M;
char a[MAXN], b[MAXN];
int q[MAXD], inq[MAXD], d[MAXD];
int init()
{
	int i, j;
	scanf("%d%d", &N, &M);
	if (!N && !M)
	{
		return 0;
	}
	memset(s, 0, sizeof(s));
	memset(t, 0, sizeof(t));
	for (i = 0; i < M; i++)
	{
		scanf("%d%s%s", &w[i], a, b);
		for (j = 0; j < N; j++)
		{
			if (a[j] == '+')
			{
				s[1][i] += (1 << j);
			}
			if (a[j] != '-')
			{
				s[0][i] += (1 << j);
			}
			if (b[j] == '+')
			{
				t[1][i] += (1 << j);
			}
			if (b[j] != '-')
			{
				t[0][i] += (1 << j);
			}
		}
	}
	return 1;
}
void SPFA()
{
	int i, j, k, MAX, front, rear, u, v;
	MAX = 1 << N;
	for (i = 0; i < MAX; i++)
	{
		d[i] = INF;
		inq[i] = 0;
	}
	front = rear = 0;
	d[MAX - 1] = 0;
	q[rear++] = MAX - 1;
	while (front != rear)
	{
		u = q[front++];
		if (front > MAX)
		{
			front = 0;
		}
		inq[u] = 0;
		for (i = 0; i < M; i++)
			if ((u | s[1][i]) == u && (u & s[0][i]) == u)
			{
				v = u;
				v |= t[1][i];
				v &= t[0][i];
				if (d[u] + w[i] < d[v])
				{
					d[v] = d[u] + w[i];
					if (!inq[v])
					{
						q[rear++] = v;
						if (rear > MAX)
						{
							rear = 0;
						}
						inq[v] = 1;
					}
				}
			}
	}
	if (d[0] == INF)
	{
		printf("Bugs cannot be fixed.\n");
	}
	else
	{
		printf("Fastest sequence takes %d seconds.\n", d[0]);
	}
}
int main()
{
	int T = 0;
	while (init())
	{
		printf("Product %d\n", ++T);
		SPFA();
		printf("\n");
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define MAXD 110
#define MAXM 20100

const long long int INF = 10000000000000000ll;

int fst[MAXD], nxt[MAXM], v[MAXM], a[MAXM], b[MAXM], p[MAXD], link[MAXD], q[MAXD], inq[MAXD], N, M, e;
long long int w[MAXM], cost[MAXM], flow[MAXM], d[MAXD], D, K;

void add(int x, int y, long long int c, long long int f)
{
	v[e] = y;
	cost[e] = c;
	flow[e] = f;
	nxt[e] = fst[x];
	fst[x] = e;
	e++;
}
int init()
{
	int i;
	if (scanf("%d%d", &N, &M) != 2)
	{
		return 0;
	}
	for (i = 0; i < M; i++)
	{
		scanf("%d%d%lld", &a[i], &b[i], &w[i]);
	}
	scanf("%lld%lld", &D, &K);
	e = 0;
	memset(fst, -1, sizeof(fst));
	for (i = 0; i < M; i++)
	{
		add(a[i], b[i], w[i], K);
		add(b[i], a[i], -w[i], 0);
		add(b[i], a[i], w[i], K);
		add(a[i], b[i], -w[i], 0);
	}
	add(0, 1, 0, D);
	add(1, 0, 0, 0);
	return 1;
}
void SPFA()
{
	int i, u, front, rear;
	for (i = 1; i <= N; i++)
	{
		d[i] = INF;
	}
	d[0] = 0;
	memset(inq, 0, sizeof(inq));
	front = rear = 0;
	q[rear++] = 0;
	inq[0] = 1;
	while (front != rear)
	{
		u = q[front++];
		if (front > N)
		{
			front = 0;
		}
		inq[u] = 0;
		for (i = fst[u]; i != -1; i = nxt[i])
		{
			if (flow[i] && d[u] + cost[i] < d[v[i]])
			{
				d[v[i]] = d[u] + cost[i];
				p[v[i]] = u;
				link[v[i]] = i;
				if (!inq[v[i]])
				{
					q[rear++] = v[i];
					if (rear > N)
					{
						rear = 0;
					}
					inq[v[i]] = 1;
				}
			}
		}
	}
}
long long int mincost()
{
	long long int res = 0, f = 0, a;
	int i, u;
	for (;;)
	{
		SPFA();
		if (d[N] == INF)
		{
			break;
		}
		a = INF;
		for (u = N; u != 0; u = p[u])
		{
			int y = link[u];
			if (flow[y] < a)
			{
				a = flow[y];
			}
		}
		for (u = N; u != 0; u = p[u])
		{
			int y = link[u];
			flow[y] -= a;
			flow[y ^ 1] += a;
		}
		res += a * d[N];
		f += a;
	}
	if (f == D)
	{
		return res;
	}
	else
	{
		return -1;
	}
}

int main()
{
	while (init())
	{
		long long int res = mincost();
		if (res >= 0)
		{
			printf("%lld\n", res);
		}
		else
		{
			printf("Impossible.\n");
		}
	}
	return 0;
}

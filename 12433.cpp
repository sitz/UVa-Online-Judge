#include <bits/stdc++.h>

using namespace std;

const int oo = 0x3f3f3f3f;
const int Max = 256;
const int MaxE = 200000;
const int MaxC = 10000;

struct queue
{
	int q[Max], s, t;
	bool empty()
	{
		return s == t;
	}
	void push(int x)
	{
		q[s++] = x;
		if (s >= Max)
		{
			s -= Max;
		}
	}
	int pop()
	{
		int x = q[t++];
		if (t >= Max)
		{
			t -= Max;
		}
		return x;
	}
} Q;

struct box
{
	int to, f, c;
	box *r, *s;
} edge[MaxE], *hd[Max], *u[Max], *r[Max], *cp;

int fa[Max], dis[Max], n, s, t;
bool inQ[Max];

box *addEdge(int x, int y, int f, int c)
{
	box *p = cp++, *q = cp++;
	p->to = y, q->to = x;
	p->f = f, q->f = 0;
	p->c = c, q->c = -c;
	p->s = hd[x], hd[x] = p;
	q->s = hd[y], hd[y] = q;
	p->r = q, q->r = p;
	return p;
}

bool spfa()
{
	memset(dis, 0x3f, sizeof(dis[0]) * n);
	dis[s] = 0, inQ[s] = true;
	Q.push(s);
	int x, y, d;
	while (!Q.empty())
	{
		d = dis[x = Q.pop()];
		inQ[x] = false;
		if (x == t)
		{
			continue;
		}
		for (box *p = hd[x]; p; p = p->s)
			if (p->f > 0 && d + p->c < dis[y = p->to])
			{
				dis[y] = d + p->c;
				fa[y] = x, u[y] = p;
				if (!inQ[y])
				{
					Q.push(y);
					inQ[y] = true;
				}
			}
	}
	return dis[t] < oo;
}
void minCost(int &res, int &flow)
{
	while (spfa())
	{
		int d = oo, x = t;
		while (x != s)
		{
			if (u[x]->f < d)
			{
				d = u[x]->f;
			}
			r[fa[x]] = u[x];
			x = fa[x];
		}
		while (x != t)
		{
			r[x]->f -= d, r[x]->r->f += d;
			x = r[x]->to;
		}
		res += d * dis[t];
		flow += d;
	}
}

const int MaxF = 64;
int V[MaxF], C[MaxF], P[MaxF], D[MaxF], S[MaxF];

int main()
{
	int tCase;
	scanf("%d", &tCase);
	for (int ct = 1; ct <= tCase; ct++)
	{
		int N, Cp, Sr;
		scanf("%d%d%d", &N, &Cp, &Sr);
		int Sum = 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &V[i]);
			Sum += V[i];
		}
		for (int i = 0; i < Cp; i++)
		{
			scanf("%d%d", &C[i], &P[i]);
		}
		for (int i = 0; i < Sr; i++)
		{
			scanf("%d%d", &D[i], &S[i]);
		}
		n = N * 2 + Cp + 3;
		s = n - 1, t = n - 2;
		memset(hd, 0, sizeof(hd[0]) * n);
		cp = edge;
		int s2 = n - 3;
		for (int i = 0; i < Cp; i++)
		{
			addEdge(s, i + N * 2, C[i], P[i]);
			addEdge(i + N * 2, s2, C[i], 0);
		}
		for (int i = 0; i < N; i++)
		{
			addEdge(s, i * 2, V[i], 0);
			addEdge(s2, i * 2 + 1, V[i], 0);
			for (int j = 0; j < Sr; j++)
			{
				int x = i + D[j] + 1;
				if (x < N)
				{
					addEdge(i * 2, x * 2 + 1, oo, S[j]);
				}
			}
			if (i + 1 < N)
			{
				addEdge(i * 2, (i + 1) * 2, oo, 0);
			}
			addEdge(i * 2 + 1, t, V[i], 0);
		}
		int Res = 0, Flow = 0;
		minCost(Res, Flow);
		printf("Case %d: ", ct);
		if (Flow < Sum)
		{
			puts("impossible");
		}
		else
		{
			printf("%d\n", Res);
		}
	}
	return 0;
}

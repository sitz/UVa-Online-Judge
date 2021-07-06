#include <bits/stdc++.h>

using namespace std;

#define MAXN 302

int R[MAXN], P[MAXN], r[MAXN], p[MAXN];
struct ss
{
	int u, v;
} edge[100000];
void Ini()
{
	int i;
	for (i = 0; i < 300; i++)
	{
		p[i] = P[i] = i;
		r[i] = R[i] = 0;
	}
}
int FindSet(int s)
{
	if (s != P[s])
	{
		P[s] = FindSet(P[s]);
	}
	return P[s];
}
int Find(int s)// 2nd
{
	if (s != p[s])
	{
		p[s] = Find(p[s]);
	}
	return p[s];
}
void Link(int x, int y)
{
	if (R[x] > R[y])
	{
		P[y] = x;
	}
	else
	{
		P[x] = y;
		if (R[x] == R[y])
		{
			R[y]++;
		}
	}
}
void Link1(int x, int y)// 2nd
{
	if (r[x] > r[y])
	{
		p[y] = x;
	}
	else
	{
		p[x] = y;
		if (r[x] == r[y])
		{
			r[y]++;
		}
	}
}
void MakeLink(int x, int y)
{
	int u, v;
	u = FindSet(x);
	v = FindSet(y);
	if (u != v)
	{
		Link(u, v);
	}
}
void Make(int x, int y)// 2nd
{
	int u, v;
	u = Find(x);
	v = Find(y);
	if (u != v)
	{
		Link1(u, v);
	}
}
void Final(int n)
{
	int i, u, v, nott = 0;
	for (i = 0; i < n; i++)
	{
		u = Find(edge[i].u);
		v = Find(edge[i].v);
		if (u != v)
		{
			nott = 1;
			break;
		}
	}
	printf(nott ? "NO\n" : "YES\n");
}
void Cal(int m, int n)
{
	int i, u, v, nott = 0;
	char temp[10], dum[10];
	for (i = 0; i < m; i++)
	{
		scanf("%s%s", temp, dum);
		if (nott)
			continue;
		u = temp[0];
		v = dum[0];
		u = FindSet(u);
		v = FindSet(v);
		if (u != v)
			nott = 1;
		Make(temp[0], dum[0]);
	}
	if (nott)
	{
		printf("NO\n");
		return;
	}
	Final(n);
}

int main()
{
	int kases, i, n, m, u, v;
	char temp[10], dum[10];
	scanf("%d", &kases);
	while (kases--)
	{
		Ini();
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%s%s", temp, dum);
			u = temp[0];
			v = dum[0];
			edge[i].u = u;
			edge[i].v = v;
			MakeLink(u, v);
		}
		scanf("%d", &m);
		Cal(m, n);
		if (kases)
			printf("\n");
	}
	return 0;
}

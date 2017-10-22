#include <bits/stdc++.h>

using namespace std;

#define maxn 30

char link[maxn][maxn], color[maxn], Hv[maxn];
int Adj[maxn];

int Add(char ss[])
{
	int i, u, v, f = 1;
	for (i = 0; ss[i]; i++)
	{
		if (isalpha(ss[i]))
		{
			u = ss[i] - 'A';
			f = 0;
			break;
		}
	}
	if (f)
		return f;
	for (++i; ss[i]; i++)
	{
		if (isalpha(ss[i]))
		{
			v = ss[i] - 'A';
			f = 0;
			break;
		}
	}
	if (f)
		return 1;
	Hv[u] = 1;
	Hv[v] = 1;
	if (u != v)
	{
		Adj[u]++;
		Adj[v]++;
		link[u][v] = link[v][u] = 1;
	}
	return 0;
}
void Recur(int n)
{
	int i;
	color[n] = 1;
	for (i = 0; i < 26; i++)
		if (link[n][i] && color[i] == 0)
			Recur(i);
}
void Cal(char ss[])
{
	int i, u, t, ac;
	t = ac = 0;
	for (i = 0; ss[i]; i++)
	{
		if (isalpha(ss[i]))
		{
			u = ss[i] - 'A';
			Hv[u] = 1;
		}
	}
	for (i = 0; i < 26; i++)
	{
		if (Hv[i])
		{
			u = i;
			if (color[u] == 1)
				continue;
			if (Adj[u] == 0)
				ac++;
			else
			{
				Recur(u);
				t++;
			}
		}
	}
	printf("There are %d tree(s) and %d acorn(s).\n", t, ac);
}
void Free()
{
	int i, j;
	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 26; j++)
			link[i][j] = 0;
		Adj[i] = color[i] = 0;
		Hv[i] = 0;
	}
}

int main()
{
	int ks;
	char ss[100];
	gets(ss);
	sscanf(ss, "%d", &ks);
	while (ks--)
	{
		while (1)
		{
			gets(ss);
			if (Add(ss))
				break;
		}
		gets(ss);
		Cal(ss);
		Free();
	}
	return 0;
}

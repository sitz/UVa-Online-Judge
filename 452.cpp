#include <bits/stdc++.h>

using namespace std;

#define MAXN 27

char color[MAXN], flag[MAXN];
int Day[MAXN], Tday[MAXN], link[MAXN][MAXN], maxlen;

struct node
{
	int n;
	node *next;
};
node *lst;

void ReadCase(char str[])
{
	int u, v, i;
	char *p;
	p = strtok(str, " ");
	v = p[0] - 'A';
	if (v > maxlen)
	{
		maxlen = v;
	}
	flag[v] = 1;
	p = strtok(NULL, " ");
	Tday[v] = Day[v] = atoi(p);
	p = strtok(NULL, " ");
	if (p == NULL)
	{
		return;
	}
	for (i = 0; p[i] != '\0'; i++)
	{
		u = p[i] - 'A';
		if (u > maxlen)
		{
			maxlen = u;
		}
		link[u][v] = 1;
		flag[u] = 1;
	}
}
void topo(int n)
{
	int i;
	color[n] = 1;
	for (i = 0; i < 26; i++)
	{
		if (link[n][i] && !color[i])
		{
			topo(i);
		}
	}
	node *p;
	p = new node;
	p->next = lst;
	lst = p;
	p->n = n;
}
void Dfs()
{
	int i;
	for (i = 0; i < 26; i++)
	{
		if (flag[i] && !color[i])
		{
			topo(i);
		}
	}
}
void Count()
{
	node *x = lst;
	int i, u;
	while (x != NULL)
	{
		u = x->n;
		for (i = 0; i < 26; i++)
		{
			if (link[u][i])
			{
				if (Tday[u] + Day[i] > Tday[i])
				{
					Tday[i] = Tday[u] + Day[i];
				}
			}
		}
		x = x->next;
	}
}
void Cal()
{
	int i, max = 0;
	if (maxlen == -1)
	{
		printf("\n");
		return;
	}
	Dfs();
	Count();
	for (i = 0; i < 26; i++)
	{
		if (max < Tday[i])
		{
			max = Tday[i];
		}
	}
	printf("%d\n", max);
}
void Reset()
{
	int i, j;
	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 26; j++)
		{
			link[i][j] = 0;
		}
		Tday[i] = Day[i] = 0;
		color[i] = flag[i] = 0;
	}
}
int main()
{
	char str[100];
	int kases, i;
	gets(str);
	sscanf(str, "%d", &kases);
	gets(str);
	while (kases--)
	{
		lst = NULL;
		maxlen = -1;
		while (gets(str))
		{
			for (i = 0; str[i]; i++)
			{
				if (str[i] == '\n')
				{
					str[i] = '\0';
					break;
				}
			}
			if (strlen(str) == 0)
			{
				break;
			}
			ReadCase(str);
		}
		Cal();
		if (kases)
		{
			putchar('\n');
			Reset();
		}
	}
	return 0;
}

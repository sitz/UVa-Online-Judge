#include <bits/stdc++.h>

using namespace std;

#define MAXN 302

struct ss
{
	int child[MAXN];
	int parent;
	int ind;
} Node[MAXN];
int Fg[MAXN];
map<string, int> M;

inline void ReadRelation()
{
	char pr[35], ch[35];
	int ind = 1, p = 0, c = 0;
	while (1)
	{
		scanf("%s%s", pr, ch);
		if (!strcmp(pr, "no.child"))
		{
			break;
		}
		c = M[pr];
		if (!c)
		{
			c = ind++;
			M[pr] = c;
		}
		p = M[ch];
		if (!p)
		{
			p = ind++;
			M[ch] = p;
		}
		Node[p].child[Node[p].ind++] = c;
		Node[c].parent = p;
	}
}

inline int isParent(int n, int level, int v)
{
	int i, k;
	if (n == v)
		return level;
	for (i = 0; i < Node[n].ind; i++)
	{
		k = isParent(Node[n].child[i], level + 1, v);
		if (k)
			return k;
	}
	return 0;
}

inline int isChild(int n, int level, int v)
{
	int i, k;
	if (n == 0)
		return 0;
	if (n == v)
		return level;
	k = isChild(Node[n].parent, level + 1, v);
	if (k)
		return k;
	return 0;
}

inline int isSibling(int u, int v)
{
	return Node[u].parent == Node[v].parent;
}

inline void Cousin1(int n, int level)
{
	if (n == 0)
		return;
	Fg[n] = level;
	Cousin1(Node[n].parent, level + 1);
}

int F;

inline int Cousin2(int n, int level)
{
	if (n == 0)
		return 0;
	if (Fg[n])
	{
		F = level;
		return Fg[n];
	}
	return Cousin2(Node[n].parent, level + 1);
}

inline void Cal(char pp[], char ch[])
{
	int i, u, v, k, m, n;
	u = M[pp];
	v = M[ch];
	if (!u || !v)
	{
		printf("no relation\n");
		return;
	}
	k = isParent(u, 1, v);
	if (k)
	{
		k -= 2;
		if (!k)
			printf("parent\n");
		if (k == 1)
			printf("grand parent\n");
		if (k > 1)
		{
			for (i = 1; i <= k - 1; i++)
				printf("great ");
			printf("grand parent\n");
		}
		return;
	}
	k = isChild(u, 1, v);
	if (k)
	{
		k -= 2;
		if (!k)
			printf("child\n");
		if (k == 1)
			printf("grand child\n");
		if (k > 1)
		{
			for (i = 1; i <= k - 1; i++)
				printf("great ");
			printf("grand child\n");
		}
		return;
	}
	if (isSibling(u, v))
	{
		printf("sibling\n");
		return;
	}
	F = 0;
	memset(Fg, 0, sizeof(int) * MAXN);
	Cousin1(u, 1);
	m = Cousin2(v, 1);
	if (!m)
	{
		printf("no relation\n");
		return;
	}
	m -= 2;
	n = F - 2;
	k = abs(m - n);
	if (!k)
	{
		printf("%d cousin\n", m);
		return;
	}
	i = m > n ? n : m;
	printf("%d cousin removed %d\n", i, k);
}

int main()
{
	char pp[35], ch[35];
	ReadRelation();
	while (scanf("%s%s", pp, ch) != EOF)
	{
		Cal(pp, ch);
	}
	return 0;
}

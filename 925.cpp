#include <bits/stdc++.h>

using namespace std;

typedef struct _trie
{
	int id, u;
	struct _trie *ch[26];
} trie;
trie *root;
int ID, L[128][128] = {0}, len;
char C[128][25];
trie *make()
{
	trie *r = (trie *)malloc(sizeof(trie));
	int i;
	r->u = 0;
	for (i = 0; i < 26; i++)
	{
		r->ch[i] = NULL;
	}
	return r;
}
void insert(char s[])
{
	trie *proc = root;
	int i, j;
	for (i = 0; s[i]; i++)
	{
		j = s[i] - 'a';
		if (proc->ch[j] == NULL)
		{
			proc->ch[j] = make();
		}
		proc = proc->ch[j];
	}
	proc->u = 1;
}
int find(char s[])
{
	trie *proc = root;
	int i, j;
	for (i = 0; s[i]; i++)
	{
		j = s[i] - 'a';
		if (proc->ch[j] == NULL)
		{
			return -1;
		}
		proc = proc->ch[j];
	}
	if (proc->u)
	{
		return proc->id;
	}
	else
	{
		return -1;
	}
}
void name(trie *x, int lv)
{
	if (x == NULL)
	{
		return;
	}
	int i, j;
	if (x->u)
	{
		x->id = ID;
		C[ID++][lv] = '\0';
		for (i = 0; i < lv; i++)
		{
			C[ID][i] = C[ID - 1][i];
		}
	}
	for (i = 0; i < 26; i++)
	{
		C[ID][lv] = 'a' + i;
		name(x->ch[i], lv + 1);
	}
}
void des(trie *x)
{
	if (x == NULL)
	{
		return;
	}
	int i;
	for (i = 0; i < 26; i++)
	{
		des(x->ch[i]);
	}
	free(x);
}
int main()
{
	int t, n, m, r, x, y, i, j, k;
	char in[25];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		root = make();
		for (i = 0; i < n; i++)
		{
			scanf("%s", in);
			insert(in);
			for (j = 0; j < n; j++)
			{
				L[i][j] = 0;
			}
		}
		ID = 0;
		scanf("%d", &r);
		name(root, 0);
		for (i = 0; i < r; i++)
		{
			scanf("%s", in);
			x = find(in);
			scanf("%d", &len);
			for (j = 0; j < len; j++)
			{
				scanf("%s", in);
				y = find(in);
				L[x][y] = 1;
			}
		}
		for (j = 0; j < n; j++)
		{
			for (i = 0; i < n; i++)
			{
				if (i == j)
				{
					continue;
				}
				for (k = 0; k < n; k++)
				{
					if (i == k || j == k)
					{
						continue;
					}
					if (L[i][j] && L[j][k])
					{
						L[i][k] = 2;
					}
				}
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = len = 0; j < n; j++)
			{
				if (L[i][j] == 1)
				{
					len++;
				}
			}
			if (len)
			{
				printf("%s %d", C[i], len);
			}
			else
			{
				continue;
			}
			for (j = 0; j < n; j++)
			{
				if (L[i][j] == 1)
				{
					printf(" %s", C[j]);
				}
			}
			printf("\n");
		}
		des(root);
	}
	return 0;
}

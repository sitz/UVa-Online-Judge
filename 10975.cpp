#include <bits/stdc++.h>

using namespace std;

#define MAX 1048576

int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

char *list_[16384], tab[128][128], alpha[MAX];
int cnt[16384], n, nrows, ncols, child[MAX], sib[MAX], last, got[16384], ID;
short term[MAX];

void go(int y, int x, int d)
{
	int p;
	for (p = 0;; y += dy[d], x += dx[d])
	{
		for (p = child[p]; alpha[p] < tab[y][x]; p = sib[p])
			;
		if (alpha[p] != tab[y][x])
		{
			return;
		}
		if (term[p])
		{
			if (got[term[p] - 1] != ID)
			{
				got[term[p] - 1] = ID;
				cnt[term[p] - 1] = 1;
			}
			else
			{
				cnt[term[p] - 1]++;
			}
		}
	}
}

void insert(char *s, int id)
{
	int p, x;
	for (p = 0; *s; s++)
	{
		for (x = child[p]; x != 0 && alpha[x] != *s; x = sib[x])
			;
		if (x != 0)
		{
			p = x;
			continue;
		}
		sib[last] = child[p];
		child[p] = last;
		p = last;
		last++;
		alpha[p] = *s;
		term[p] = 0;
		child[p] = 0;
	}
	term[p] = id;
}

int cmp(const void *p, const void *q)
{
	return strcmp(*(char **)p, *(char **)q);
}

void solve()
{
	static char buf[65536];
	int i, j, k, q, nq;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf(" %[a-z]", buf);
		list_[i] = strdup(buf);
	}
	qsort(list_, n, sizeof(list_[0]), &cmp);
	last = 1;
	child[0] = sib[0] = term[0] = 0;
	alpha[0] = 127;
	for (i = n; i-- > 0;)
	{
		insert(list_[i], i + 1);
	}
	scanf("%d", &nq);
	for (q = 1; q <= nq; q++)
	{
		scanf("%d %d", &nrows, &ncols);
		printf("Query #%d\n", q);
		for (i = 0; i <= nrows + 1; i++)
			for (j = 0; j <= ncols + 1; j++)
			{
				tab[i][j] = ' ';
			}
		for (i = 1; i <= nrows; i++)
			for (j = 1; j <= ncols; j++)
			{
				while ((k = getchar()) != EOF && k == '\n')
					;
				tab[i][j] = ('a' <= k && k <= 'z') ? k : ' ';
			}
		ID++;
		for (i = 1; i <= nrows; i++)
			for (j = 1; j <= ncols; j++)
				for (k = 0; k < 8; k++)
				{
					go(i, j, k);
				}
		for (i = 0; i < n; i++)
			if (got[i] == ID)
			{
				printf("%s %d\n", list_[i], cnt[i]);
			}
	}
	for (i = 0; i < n; i++)
	{
		free(list_[i]);
	}
}

int main()
{
	int c, t;
	ID = 42;
	for (scanf("%d", &t), c = 1; c <= t; c++)
	{
		printf("Test Case #%d\n", c);
		solve();
		printf("\n");
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define MAXN 95

typedef unsigned long long xx;

struct sss
{
	int A[MAXN];
	int ind;
} link[MAXN];
struct zz
{
	int A[MAXN];
	int ind;
	int fre[MAXN];
} tmp[MAXN];
char Rule[MAXN], H[MAXN];
int Str[MAXN], rule[MAXN];
xx Fre[10002][MAXN];
int R, Q, max, min, tr;

void Set(char ss[])
{
	int i, j, k;
	k = ss[0] - 33;
	Rule[k] = 1;
	rule[tr++] = k;
	link[k].ind = 0;
	for (i = 3; ss[i]; i++)
	{
		j = ss[i] - 33;
		link[k].A[link[k].ind++] = j;
	}
}
void Free(int limit, int n)
{
	int i, j;
	for (i = 1; i <= limit + 1; i++)
	{
		for (j = 0; j < R; j++)
		{
			Fre[i][rule[j]] = 0;
		}
		Fre[i][n] = 0;
	}
}
void Count(int n, char ss[], int limit)
{
	int i, j, ind = 1, k, m = 0;
	int tc = 0, l, y, p;
	int ff[100] = {0};
	for (i = 0; i < MAXN; i++)
	{
		H[i] = 0;
		Fre[0][i] = 0;
	}
	for (i = 0; ss[i]; i++)
	{
		k = ss[i] - 33;
		if (n != k && !Rule[k])
		{
			continue;
		}
		if (H[k] == 0)
		{
			Str[tc++] = k;
			H[k] = 1;
		}
		Fre[0][k]++;
	}
	for (i = 0; i < R; i++)
	{
		j = rule[i];
		tmp[j].ind = 0;
		for (k = 0; k < link[j].ind; k++)
		{
			m = link[j].A[k];
			if (!Rule[m] && m != n)
			{
				continue;
			}
			if (ff[m] == 0)
			{
				tmp[j].A[tmp[j].ind++] = m;
				tmp[j].fre[tmp[j].ind - 1] = 1;
				ff[m] = tmp[j].ind;
			}
			else
			{
				tmp[j].fre[ff[m] - 1]++;
			}
		}
		for (k = 0; k < R; k++)
		{
			ff[rule[k]] = 0;
		}
		ff[n] = 0;
	}
	l = tc;
	m = 0;
	Free(limit, n);
	while (m++ < limit)
	{
		for (i = 0; i < l; i++)
		{
			k = Str[i];
			if (Rule[k])
			{
				for (y = 0; y < tmp[k].ind; y++)
				{
					p = tmp[k].A[y];
					Fre[ind][p] += Fre[ind - 1][k] * tmp[k].fre[y];
					if (H[p] == 0)
					{
						H[p] = 1;
						Str[tc++] = p;
					}
				}
			}
			else
			{
				Fre[ind][k] += Fre[ind - 1][k];
			}
		}
		ind++;
		l = tc;
	}
	printf("%llu\n", Fre[ind - 1][n]);
}
void Cal()
{
	int st, k;
	char str[200], ch[5];
	scanf("%d", &Q);
	while (Q--)
	{
		scanf("%s%s%d", str, ch, &st);
		k = ch[0] - 33;
		Count(k, str, st);
	}
}

int main()
{
	int ks, i;
	char temp[200];
	scanf("%d", &ks);
	while (ks--)
	{
		scanf("%d", &R);
		i = tr = 0;
		while (i < R)
		{
			scanf("%s", temp);
			Set(temp);
			i++;
		}
		Cal();
		for (i = 0; i < R; i++)
			Rule[rule[i]] = 0;
	}
	return 0;
}

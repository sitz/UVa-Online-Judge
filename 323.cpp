#include <bits/stdc++.h>

using namespace std;

#define SHIFT 4096

typedef struct
{
	int m, diff, sum;
	unsigned a[8];
} jury_t;

jury_t list_[163840], list_new[163840];
int tab[32][8192], cnt, m;

void add(int p, int d, int s)
{
	int i, j, k, r;
	for (i = 1, r = 0; i <= cnt; i++)
	{
		if (list_[i].m >= m)
		{
			continue;
		}
		j = tab[list_[i].m + 1][SHIFT + list_[i].diff + d];
		if (j > 0 && list_[j].sum >= (list_[i].sum + s))
		{
			continue;
		}
		list_new[r].m = list_[i].m + 1;
		list_new[r].diff = list_[i].diff + d;
		list_new[r].sum = list_[i].sum + s;
		for (k = 0; k < 8; k++)
		{
			list_new[r].a[k] = list_[i].a[k];
		}
		list_new[r].a[p >> 5] |= 1U << (p & 31);
		r++;
	}
	while (r-- > 0)
	{
		j = tab[list_new[r].m][SHIFT + list_new[r].diff];
		if (j > 0 && list_[j].sum >= list_new[r].sum)
		{
			continue;
		}
		if (j == 0)
		{
			j = ++cnt;
		}
		memcpy(&list_[j], &list_new[r], sizeof(jury_t));
		tab[list_[j].m][SHIFT + list_[j].diff] = j;
	}
}

int main()
{
	int i, j, n, t, x, y;
	for (t = 1; scanf("%d %d", &n, &m) == 2 && n > 0; t++)
	{
		printf("Jury #%d\n", t);
		memset(tab, 0, sizeof(tab));
		memset(list_, 0, 2 * sizeof(jury_t));
		cnt = 1;
		for (i = 0; i < n && scanf("%d %d", &x, &y) == 2; i++)
		{
			add(i, x - y, x + y);
		}
		for (i = 0;; i++)
			if ((tab[m][SHIFT + i] | tab[m][SHIFT - i]) != 0)
			{
				break;
			}
		if (tab[m][SHIFT + i] != 0)
		{
			j = tab[m][SHIFT + i];
		}
		else
		{
			j = tab[m][SHIFT - i];
		}
		if (tab[m][SHIFT - i] != 0)
			if (list_[tab[m][SHIFT - i]].sum > list_[j].sum)
			{
				j = tab[m][SHIFT - i];
			}
		printf("Best jury has value %d for prosecution and value %d for defence:\n",
					 (list_[j].diff + list_[j].sum) / 2,
					 (list_[j].sum - list_[j].diff) / 2);
		for (i = 0; i < n; i++)
			if ((list_[j].a[i >> 5] >> (i & 31)) & 1)
			{
				printf(" %d", i + 1);
			}
		printf("\n\n");
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

char cmd[105];
int n, pp, tt, ecnt, csiz[35], ans[35], bin[30], tre[30000000], hash_[17500000];

void del(int tar)
{
	int i, loc, cc, temp;
	temp = tar;
	for (i = 0; tar; i++)
	{
		bin[i] = (tar & 1);
		tar >>= 1;
	}
	for (; i < 24; i++)
	{
		bin[i] = 0;
	}
	for (i = 23, loc = 1, cc = 0; i >= 0; i--)
	{
		if (bin[i])
		{
			cc += tre[loc];
			loc = (loc << 1) + 1;
		}
		else
		{
			tre[loc]++;
			loc <<= 1;
		}
	}
	/*printf("%d ", cc);*/
	cc = tt - (temp - cc);
	/*printf("%d\n", cc);*/
	for (i = 0; i < n; i++)
	{
		if (csiz[i] > cc)
		{
			break;
		}
		ans[i]++;
	}
}

void insert(int tar)
{
	if (hash_[tar] > 0)
	{
		del(hash_[tar]);
	}
	else
	{
		ecnt++;
		tt++;
	}
	hash_[tar] = ++pp;
}

int main()
{
	int i, p, q, r;
	while (scanf("%d", &n) == 1)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d", &csiz[i]);
		}
		memset(hash_, 0, sizeof(hash_));
		memset(ans, 0, sizeof(ans));
		ecnt = 0;
		pp = 0;
		tt = 0;
		while (scanf("%s", cmd) == 1)
		{
			if (cmd[0] == 'R')
			{
				scanf("%d%d%d", &p, &q, &r);
				for (i = 0; i < r; i++)
				{
					insert(p + q * i);
				}
			}
			else if (cmd[0] == 'A')
			{
				scanf("%d", &p);
				insert(p);
			}
			else if (cmd[0] == 'S')
			{
				printf("%d", ans[0] + ecnt);
				for (i = 1; i < n; i++)
				{
					printf(" %d", ans[i] + ecnt);
				}
				printf("\n");
				memset(ans, 0, sizeof(ans));
				ecnt = 0;
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}

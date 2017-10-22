#include <bits/stdc++.h>

using namespace std;

int n, nxt[18], num[16], tbl[16][127];
char str[16][33000][17], lst[17], s[20], *ptr;

int ab(int now)
{
	if (now < 0)
	{
		return -now;
	}
	return now;
}

void dfs(int depth)
{
	int i, j, k;
	if (depth == n)
	{
		ptr = str[n][num[n]++];
		for (i = 0; i < n; i++)
		{
			ptr[i] = lst[i] + 64;
		}
		return;
	}
	for (i = 0; j = nxt[i]; i = j)
	{
		if (!(depth && ab(lst[depth - 1] - j) == 2) && !(depth > 1 && ab(lst[depth - 2] - j) == 1))
		{
			for (k = 0; k < depth; k++)
			{
				if (depth - k == ab(lst[k] - j))
				{
					break;
				}
			}
			if (k == depth)
			{
				lst[depth] = j;
				nxt[i] = nxt[j];
				dfs(depth + 1);
				nxt[i] = j;
			}
		}
	}
}

int main()
{
	int cas, i, j;
	long long count;
	cas = 0;
	for (i = 0; i < 16; i++)
	{
		nxt[i] = i + 1;
	}
	strcpy(str[1][num[1]++], "A");
	for (i = 10; i < 16; i++)
	{
		n = i;
		lst[n] = 0;
		nxt[n] = 0;
		dfs(0);
		nxt[n] = n + 1;
	}
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		memset(tbl, 0, sizeof(tbl));
		for (i = 0, count = 1; i < n; i++)
		{
			scanf("%s", s);
			if (s[0] == '?')
			{
				tbl[i][0] = 1;
				count *= n;
			}
			else
			{
				for (j = 0; s[j]; j++)
				{
					tbl[i][s[j]] = 1;
				}
				count *= j;
			}
		}
		for (i = 0; i < num[n]; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (!tbl[j][0] && !tbl[j][str[n][i][j]])
				{
					break;
				}
			}
			count -= (j == n);
		}
		printf("Case %d: %lld\n", ++cas, count);
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int tbl[34];
char name[7][11] = {"DONG", "NAN", "XI", "BEI", "ZHONG", "FA", "BAI"};
char buf[101];

int trans(char *s)
{
	int i;
	for (i = 0; i < 7; i++)
	{
		if (!strcmp(s, name[i]))
		{
			return 27 + i;
		}
	}
	if (s[1] == 'T')
	{
		return s[0] - '1';
	}
	else if (s[1] == 'S')
	{
		return 9 + s[0] - '1';
	}
	return 18 + s[0] - '1';
}

char *tile(int n)
{
	if (n < 9)
	{
		sprintf(buf, "%dT\0", n + 1);
	}
	else if (n < 18)
	{
		sprintf(buf, "%dS\0", n - 8);
	}
	else if (n < 27)
	{
		sprintf(buf, "%dW\0", n - 17);
	}
	else
	{
		strcpy(buf, name[n - 27]);
	}
	return buf;
}

int dfs(int depth, int eye)
{
	int temp;
	if (depth == 34)
	{
		return eye == 1;
	}
	if (!tbl[depth])
	{
		return dfs(depth + 1, eye);
	}
	if (depth < 27)
	{
		temp = depth % 9;
		if (temp < 7 && tbl[depth + 1] && tbl[depth + 2])
		{
			tbl[depth]--;
			tbl[depth + 1]--;
			tbl[depth + 2]--;
			if (dfs(depth, eye))
			{
				tbl[depth]++;
				tbl[depth + 1]++;
				tbl[depth + 2]++;
				return 1;
			}
			tbl[depth]++;
			tbl[depth + 1]++;
			tbl[depth + 2]++;
		}
	}
	if (tbl[depth] > 1 && !eye)
	{
		tbl[depth] -= 2;
		if (dfs(depth, eye + 1))
		{
			tbl[depth] += 2;
			return 1;
		}
		tbl[depth] += 2;
	}
	if (tbl[depth] > 2)
	{
		tbl[depth] -= 3;
		if (dfs(depth, eye))
		{
			tbl[depth] += 3;
			return 1;
		}
		tbl[depth] += 3;
	}
	return 0;
}

int main()
{
	int cas, i, ans;
	cas = 0;
	while (1)
	{
		memset(tbl, 0, sizeof(tbl));
		for (i = 0; i < 13; i++)
		{
			scanf("%s", buf);
			if (buf[0] == '0')
			{
				break;
			}
			tbl[trans(buf)]++;
		}
		if (i < 13)
		{
			break;
		}
		printf("Case %d:", ++cas);
		for (i = 0, ans = 0; i < 34; i++)
		{
			if (tbl[i] < 4)
			{
				tbl[i]++;
				if (dfs(0, 0))
				{
					printf(" %s", tile(i));
					ans = 1;
				}
				tbl[i]--;
			}
		}
		if (!ans)
		{
			printf(" Not ready");
		}
		printf("\n");
	}
	return 0;
}

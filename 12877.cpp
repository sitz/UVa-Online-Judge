#include <bits/stdc++.h>

using namespace std;

int mp[200], L[50], n, ret;
bool inv[200], used[10];
char str[50][50];

void work(int num, int pos, int sum)
{
	int i, j, k, v;
	k = L[num] - pos;
	if (num == n)
	{
		j = mp[str[n][k]];
		if (j != -1)
		{
			if (j != sum % 10)
			{
				return;
			}
			if (k == 0)
			{
				if (sum / 10 == 0)
				{
					ret++;
				}
				return;
			}
			work(1, pos + 1, sum / 10);
		}
		else
		{
			v = sum % 10;
			if (used[v])
			{
				return;
			}
			if (v == 0 && inv[str[n][k]])
			{
				return;
			}
			//used[v]=1;
			//mp[str[n][k]]=v;
			if (k == 0)
			{
				if (sum / 10 == 0)
				{
					ret++;
				}
				return;
			}
			used[v] = 1;
			mp[str[n][k]] = v;
			work(1, pos + 1, sum / 10);
			used[v] = 0;
			mp[str[n][k]] = -1;
		}
	}
	else
	{
		if (k < 0)
		{
			work(num + 1, pos, sum);
			return;
		}
		if (mp[str[num][k]] != -1)
		{
			sum += mp[str[num][k]];
			work(num + 1, pos, sum);
		}
		else
		{
			if (inv[str[num][k]] == 0 && used[0] == 0)
			{
				mp[str[num][k]] = 0;
				used[0] = 1;
				work(num + 1, pos, sum);
				used[0] = 0;
				mp[str[num][k]] = -1;
			}
			for (i = 1; i <= 9; i++)
			{
				if (used[i] == 0)
				{
					mp[str[num][k]] = i;
					used[i] = 1;
					work(num + 1, pos, sum + i);
					used[i] = 0;
					mp[str[num][k]] = -1;
				}
			}
		}
	}
}

int main()
{
	int i, j, k;
	while (scanf("%d", &n) == 1)
	{
		ret = 0;
		memset(mp, -1, sizeof(mp));
		memset(inv, 0, sizeof(inv));
		memset(used, 0, sizeof(used));
		for (i = 1; i <= n; i++)
		{
			scanf("%s", str[i]);
			L[i] = strlen(str[i]);
			inv[str[i][0]] = 1;
		}
		work(1, 1, 0);
		printf("%d\n", ret);
	}
	return 0;
}

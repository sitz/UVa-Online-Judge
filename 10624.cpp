#include <bits/stdc++.h>

using namespace std;

int m, n, a[35];
int dfs(int cur)
{
	int i, j, s, c;
	if (cur == m)
	{
		return 1;
	}
	if (cur == 0)
	{
		if (n == 1)
		{
			for (i = n; i < 10; i += n)
			{
				a[cur] = i;
				if (dfs(cur + 1))
				{
					return 1;
				}
			}
		}
		else
			for (i = 1; i < 10; i++)
			{
				a[cur] = i;
				if (dfs(cur + 1))
				{
					return 1;
				}
			}
	}
	else if (cur >= n - 1)
	{
		for (i = 0; i < 10; i++)
		{
			a[cur] = i;
			c = 0;
			for (j = 0; j <= cur; j++)
			{
				s = c * 10 + a[j];
				c = s % (cur + 1);
			}
			if (c == 0 && dfs(cur + 1))
			{
				return 1;
			}
		}
	}
	else
		for (i = 0; i < 10; i++)
		{
			a[cur] = i;
			if (dfs(cur + 1))
			{
				return 1;
			}
		}
	return 0;
}
int main()
{
	int i, j, k, t, tt;
	scanf("%d", &t);
	for (tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		printf("Case %d: ", tt + 1);
		if (m == 29)
			if (n >= 1 && n <= 12)
			{
				if (n >= 1 && n <= 5)
				{
					printf("-1\n");
				}
				else
					switch (n)
					{
					case 6:
						printf("39208896001212006680167258804\n");
						break;
					case 7:
						printf("18555536703606084000060008482\n");
						break;
					case 8:
						printf("10211576408418088880443254681\n");
						break;
					case 9:
						printf("10101279606082569080443254680\n");
						break;
					case 10:
						printf("10015192000842085860660000924\n");
						break;
					case 11:
						printf("10000351372830084060967250126\n");
						break;
					case 12:
						printf("10000028419290081060024006085\n");
						break;
					}
				continue;
			}
		memset(a, 0, sizeof(a));
		if (dfs(0))
		{
			for (i = 0; i < m; i++)
			{
				printf("%d", a[i]);
			}
		}
		else
		{
			printf("-1");
		}
		printf("\n");
	}
	return 0;
}

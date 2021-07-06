#include <bits/stdc++.h>

using namespace std;

int n, m, map_[30][30], deg[30], tbl[128];
char ary[1000][1005], buf[2008];

int main()
{
	int count, i, j, k, max, temp;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &m, &n);
		memset(map_, 0, sizeof(map_));
		memset(deg, 0, sizeof(deg));
		gets(buf);
		for (i = 0; i < n; i++)
		{
			gets(ary[i]);
			for (j = 0; ary[i][j]; j++)
			{
				if (ary[i][j] < 97 || ary[i][j] > 122)
				{
					while (1)
						;
				}
			}
			if (i)
			{
				for (j = 0; ary[i][j] && ary[i - 1][j] && ary[i][j] == ary[i - 1][j]; j++)
					;
				if (ary[i][j] && ary[i - 1][j])
				{
					map_[ary[i - 1][j] - 97][ary[i][j] - 97]++;
					deg[ary[i][j] - 97]++;
				}
			}
		}
		gets(buf);
		memset(tbl, 0, sizeof(tbl));
		for (i = 0; buf[i]; i++)
		{
			if (buf[i] >= 97 && buf[i] < 97 + m)
			{
				tbl[buf[i] - 97] = 1;
			}
		}
		for (k = 0; k < m; k++)
		{
			for (i = 0, max = 0; i < m; i++)
			{
				if (deg[i] == 0)
				{
					if (tbl[i])
					{
						if (max)
						{
							break;
						}
						max = 2;
						temp = i;
					}
					else
					{
						if (max == 2)
						{
							break;
						}
						max = 1;
						temp = i;
					}
				}
			}
			if (i == m)
			{
				tbl[temp] = k + 97;
				deg[temp]--;
				for (i = 0; i < m; i++)
				{
					deg[i] -= map_[temp][i];
				}
			}
			else
			{
				break;
			}
		}
		if (k == m)
		{
			for (i = 0; buf[i]; i++)
			{
				if (buf[i] >= 97 && buf[i] < 97 + m)
				{
					printf("%c", tbl[buf[i] - 97]);
				}
				else
				{
					printf("%c", buf[i]);
				}
			}
			printf("\n");
		}
		else
		{
			printf("Message cannot be decrypted.\n");
		}
	}
	return 0;
}

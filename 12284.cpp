#include <bits/stdc++.h>

using namespace std;

#define INF 0x3fffffff

int start[110][110], end_[110][110];

int main()
{
	int i, sum, j, ca, p = 0, n, k, sum1, a, b;
	bool flag;
	scanf("%d", &ca);
	while (ca--)
	{
		scanf("%d%d", &n, &k);
		flag = false;
		memset(start, -1, sizeof(start));
		memset(end_, -1, sizeof(end_));
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
			{
				scanf("%d", &start[i][j]);
				if (start[i][j] != start[j][i] && start[j][i] != -1)
				{
					flag = true;
				}
			}
		flag = false;
		bool yy = false;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
			{
				scanf("%d", &end_[i][j]);
				if (end_[i][j] != end_[j][i] && end_[j][i] != -1)
				{
					flag = true;
				}
				if (start[i][j] != end_[i][j])
				{
					yy = true;
				}
			}
		if (!flag && yy)
		{
			printf("Case %d: -1\n", ++p);
			continue;
		}
		sum = 0;
		sum1 = 0;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
			{
				if (start[i][j] != end_[i][j])
				{
					sum++;
					if (i != j)
					{
						sum1++;
						a = i;
						b = j;
					}
				}
			}
		if (sum1 == 0)
		{
			printf("Case %d: %d\n", ++p, sum);
			continue;
		}
		if (k == 2)
		{
			if (sum1 != 0 && n == 2)
			{
				printf("Case %d: -1\n", ++p);
				continue;
			}
		}
		flag = false;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
			{
				if (start[i][j] != end_[i][j] && i != j)
				{
					if (start[j][i] != end_[i][j])
					{
						flag = true;
					}
				}
				else if (start[i][j] != start[j][i])
				{
					flag = true;
				}
			}
		if (!flag && sum1 > 1 && n > 2 && k == 2)
		{
			printf("Case %d: %d\n", ++p, sum + 2);
		}
		else if (flag || sum1 == 1 || sum1 > 3)
		{
			printf("Case %d: %d\n", ++p, sum);
		}
		else
		{
			printf("Case %d: %d\n", ++p, sum + 1);
		}
	}
	return 0;
}

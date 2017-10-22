#include <bits/stdc++.h>

using namespace std;

int qq[105], tdx[105], tdy[105], pnum[105], ppx[105][15], ppy[105][15];
int used[105];

int get_dis(int x, int y)
{
	return x * x + y * y;
}

int main()
{
	int count, n, m, k, d, i, j, ii, jj, kk, pp;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d%d", &n, &m, &k, &d);
		d *= d;
		k *= k;
		for (i = 0; i < m; i++)
		{
			scanf("%d%d", &tdx[i], &tdy[i]);
		}
		for (i = 0; i < n; i++)
		{
			scanf("%d", &pnum[i]);
			for (j = 0; j < pnum[i]; j++)
			{
				scanf("%d%d", &ppx[i][j], &ppy[i][j]);
			}
		}
		memset(used, 0, sizeof(used));
		used[0] = 1;
		qq[0] = 0;
		for (i = 0, j = 1; i < j; i++)
		{
			pp = qq[i];
			for (ii = 0; ii < pnum[pp]; ii++)
			{
				for (jj = 0; jj < m; jj++)
				{
					if (get_dis(ppx[pp][ii] - tdx[jj], ppy[pp][ii] - tdy[jj]) <= d)
					{
						break;
					}
				}
				if (jj < m)
				{
					break;
				}
			}
			if (ii < pnum[pp])
			{
				break;
			}
			for (ii = 0; ii < n; ii++)
			{
				if (used[ii] == 0)
				{
					for (jj = 0; jj < pnum[pp]; jj++)
					{
						for (kk = 0; kk < pnum[ii]; kk++)
						{
							if (get_dis(ppx[pp][jj] - ppx[ii][kk], ppy[pp][jj] - ppy[ii][kk]) <= k)
							{
								break;
							}
						}
						if (kk < pnum[ii])
						{
							break;
						}
					}
					if (jj < pnum[pp])
					{
						used[ii] = 1;
						qq[j++] = ii;
					}
				}
			}
		}
		if (i < j)
		{
			printf("Tree can be saved :)\n");
		}
		else
		{
			printf("Tree can't be saved :(\n");
		}
	}
	return 0;
}

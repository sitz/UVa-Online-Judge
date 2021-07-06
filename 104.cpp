#include <bits/stdc++.h>

using namespace std;

enum
{
	MAX = 20
};

int main()
{
	int n; // dim(tbl)
	double profit[MAX][MAX][MAX];
	int path[MAX][MAX][MAX]; // baktrk
	while (scanf("%d", &n) == 1)
	{
		memset(profit, 0, sizeof(profit));
		// profit[0][i][j] = input
		// profit[0][i][i] = 1, for all i
		// path[0][i][j] = i, for all i, j
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i == j)
				{
					profit[0][i][j] = 1.0;
				}
				else
				{
					scanf("%lf", &profit[0][i][j]);
				}
				path[0][i][j] = i;
			}
		}

		// Floyd-Warshall
		for (int steps = 1; steps < n; ++steps)
		{
			for (int k = 0; k < n; ++k) // intermediate node k
			{
				for (int i = 0; i < n; ++i) // path from i -> j
				{
					for (int j = 0; j < n; ++j)
					{
						double tmp = profit[steps - 1][i][k] * profit[0][k][j];
						if (tmp > profit[steps][i][j])
						{
							profit[steps][i][j] = tmp;
							path[steps][i][j] = k;
						}
					}
				}
			}
		}

		// find SP to profit 1%
		int steps, tgtNo = -1; // #currency wanted
		for (steps = 1; steps < n; steps++)
		{
			for (int i = 0; i < n; i++)
			{
				if (profit[steps][i][i] > 1.01)
				{
					tgtNo = i;
					break;
				}
			}
			if (tgtNo != -1)
			{
				break;
			}
		}

		if (tgtNo == -1)
		{
			printf("no arbitrage sequence exists\n");
		}
		else
		{
			int outSeq[MAX]; // rev seq
			int idx = 0;
			int currNo = tgtNo;
			outSeq[idx++] = tgtNo;
			// tgtNo -> currNo
			for (int s = steps; s >= 0; --s)
			{
				currNo = path[s][tgtNo][currNo];
				outSeq[idx++] = currNo;
			}
			for (int i = idx - 1; i > 0; --i)
			{
				printf("%d ", outSeq[i] + 1);
			}
			printf("%d\n", outSeq[0] + 1);
		}
	}
	return 0;
}

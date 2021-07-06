#include <bits/stdc++.h>

using namespace std;

int B[10][10], P[10][10], n, nsq, nqt, over;
void trace(int proc)
{
	if (over)
	{
		return;
	}
	if (proc == nqt)
	{
		over = 1;
		return;
	}
	int x = proc / nsq, y = proc % nsq;
	if (B[x][y])
	{
		trace(proc + 1);
		return;
	}
	int i, j, fp = 0, bx = x - x % n, by = y - y % n;
	for (i = 0; i < nsq; i++)
	{
		fp = (fp | P[x][i] | P[i][y]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			fp = (fp | P[bx + i][by + j]);
		}
	}
	for (i = 1; i <= nsq; i++)
	{
		if (fp & (1 << i))
		{
			continue;
		}
		B[x][y] = i;
		P[x][y] = (1 << i);
		trace(proc + 1);
		if (over)
		{
			return;
		}
		P[x][y] = 0;
		B[x][y] = 0;
	}
}
int main()
{
	int i, j, first = 1;
	while (scanf("%d", &n) == 1)
	{
		nsq = n * n;
		nqt = nsq * nsq;
		for (i = 0; i < nsq; i++)
		{
			for (j = 0; j < nsq; j++)
			{
				scanf("%d", &B[i][j]);
				if (B[i][j])
				{
					P[i][j] = (1 << B[i][j]);
				}
				else
				{
					P[i][j] = 0;
				}
			}
		}
		over = 0;
		trace(0);
		if (first)
		{
			first = 0;
		}
		else
		{
			printf("\n");
		}
		if (!over)
		{
			printf("NO SOLUTION\n");
			continue;
		}
		for (i = 0; i < nsq; i++)
		{
			printf("%d", B[i][0]);
			for (j = 1; j < nsq; j++)
			{
				printf(" %d", B[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

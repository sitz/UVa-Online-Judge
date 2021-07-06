#include <bits/stdc++.h>

using namespace std;

int ans;
unsigned long long tbl[101][64];

void bisearch(unsigned long long *ptr, unsigned long long target, int left, int right)
{
	int center;
	if (left > right)
	{
		return;
	}
	center = left + right;
	center /= 2;
	/*printf("%d %I64u %I64d\n", center, ptr[center], target);*/
	/*printf("%d %d %d\n", center, ptr[center], target);*/
	if (ptr[center] <= target)
	{
		ans = center;
		bisearch(ptr, target, center + 1, right);
	}
	else
	{
		bisearch(ptr, target, left, center - 1);
	}
}

int main()
{
	int n, i, j;
	unsigned long long m;
	for (i = 0; i < 65; i++)
	{
		tbl[0][i] = 1;
	}
	for (i = 1; i <= 100; i++)
	{
		tbl[i][1] = 1;
		for (j = 2; j < 65; j++)
		{
			tbl[i][j] = tbl[i - 1][j - 1] + tbl[i][j - 1];
			/*if(i < 5 && j < 10) printf("%d %d => %I64u\n", i, j, tbl[i][j]);*/
		}
	}
	while (scanf("%d%llu", &n, &m) == 2)
	{
		if (!n)
		{
			break;
		}
		ans = 70;
		/*printf("%d\n", tbl[n][9]);*/
		bisearch(tbl[n], m, 1, 64);
		if (ans > 63)
		{
			printf("More than 63 trials needed.\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	return 0;
}

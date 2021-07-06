#include <bits/stdc++.h>

using namespace std;

int mm[6] = {100, 50, 20, 10, 5, 1};
int temp[5][10];
int coins[5][10];
int fim[5];
int qt[10];
int best;
int read()
{
	int ab, bc, ca;
	int inc[5];
	scanf("%d %d %d", &ab, &bc, &ca);
	inc[0] = ca - ab;
	inc[1] = ab - bc;
	inc[2] = bc - ca;
	memset(qt, 0, sizeof(qt));
	int i, j;
	for (i = 0; i < 3; i++)
	{
		fim[i] = 0;
		for (j = 0; j < 6; j++)
		{
			scanf("%d", &coins[i][j]);
			fim[i] += mm[j] * coins[i][j];
			qt[j] += coins[i][j];
		}
		fim[i] += inc[i];
	}
	return 1;
}
int rec(int p, int c, int val)
{
	if (p == 2)
	{
		int i, ret = 0;
		for (i = 0; i < 6; i++)
		{
			ret += abs(coins[0][i] - temp[0][i]) + abs(coins[1][i] - temp[1][i]) + abs(coins[2][i] - qt[i]);
		}
		ret /= 2;
		if (ret < best)
		{
			best = ret;
		}
		return 0;
	}
	if (c == 6)
	{
		if (val == fim[p])
		{
			rec(p + 1, 0, 0);
		}
		return 0;
	}
	if (val > fim[p])
	{
		return 0;
	}
	int i;
	for (i = 0; i <= qt[c]; i++)
	{
		qt[c] -= i;
		temp[p][c] = i;
		rec(p, c + 1, val + i * mm[c]);
		qt[c] += i;
	}
	return 0;
}
int process()
{
	best = 100000000;
	rec(0, 0, 0);
	if (best == 100000000)
	{
		printf("impossible\n");
	}
	else
	{
		printf("%d\n", best);
	}
	return 0;
}
int main()
{
	int casos;
	scanf("%d", &casos);
	while (casos--)
	{
		read();
		process();
	}
	return 0;
}

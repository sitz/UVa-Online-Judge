#include <bits/stdc++.h>

using namespace std;

#define RED 0
#define GREEN 1

int final, lside, rside, nextr, nextg, numr[7], numg[7];
char usedr[14], usedg[14];

struct data
{
	int id, num;
} aryr[7][7], aryg[7][7];

void dfs(int turn, int pass)
{
	int i, find, temp;
	find = 0;
	if (turn == RED)
	{
		if (nextg == 0)
		{
			final |= (1 << GREEN);
			return;
		}
		for (i = 0; i < numr[lside]; i++)
		{
			if (usedr[aryr[lside][i].id] == 0)
			{
				find = 1;
				usedr[aryr[lside][i].id] = 1;
				temp = lside;
				lside = aryr[lside][i].num;
				nextr--;
				dfs(1 - turn, 0);
				if (final == 3)
				{
					return;
				}
				nextr++;
				lside = temp;
				usedr[aryr[lside][i].id] = 0;
			}
		}
		if (lside != rside)
		{
			for (i = 0; i < numr[rside]; i++)
			{
				if (usedr[aryr[rside][i].id] == 0)
				{
					find = 1;
					usedr[aryr[rside][i].id] = 1;
					temp = rside;
					rside = aryr[rside][i].num;
					nextr--;
					dfs(1 - turn, 0);
					if (final == 3)
					{
						return;
					}
					nextr++;
					rside = temp;
					usedr[aryr[rside][i].id] = 0;
				}
			}
		}
		if (find == 0)
		{
			if (pass)
			{
				return;
			}
			dfs(1 - turn, 1);
		}
	}
	else
	{
		if (nextr == 0)
		{
			final |= (1 << RED);
			return;
		}
		for (i = 0; i < numg[lside]; i++)
		{
			if (usedg[aryg[lside][i].id] == 0)
			{
				find = 1;
				usedg[aryg[lside][i].id] = 1;
				temp = lside;
				lside = aryg[lside][i].num;
				nextg--;
				dfs(1 - turn, 0);
				if (final == 3)
				{
					return;
				}
				nextg++;
				lside = temp;
				usedg[aryg[lside][i].id] = 0;
			}
		}
		if (lside != rside)
		{
			for (i = 0; i < numg[rside]; i++)
			{
				if (usedg[aryg[rside][i].id] == 0)
				{
					find = 1;
					usedg[aryg[rside][i].id] = 1;
					temp = rside;
					rside = aryg[rside][i].num;
					nextg--;
					dfs(1 - turn, 0);
					if (final == 3)
					{
						return;
					}
					nextg++;
					rside = temp;
					usedg[aryg[rside][i].id] = 0;
				}
			}
		}
		if (find == 0)
		{
			if (pass)
			{
				return;
			}
			dfs(1 - turn, 1);
		}
	}
}

int main()
{
	int cas, n, i, l, r, max, temp, idtemp;
	cas = 0;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		memset(numr, 0, sizeof(numr));
		memset(numg, 0, sizeof(numg));
		memset(usedr, 0, sizeof(usedr));
		memset(usedg, 0, sizeof(usedg));
		for (i = 0, max = -1; i < n; i++)
		{
			scanf("%d%d", &l, &r);
			if (l == r && l > max)
			{
				max = l;
				temp = RED;
				idtemp = i;
			}
			aryr[l][numr[l]].id = i;
			aryr[l][numr[l]++].num = r;
			if (l != r)
			{
				aryr[r][numr[r]].id = i;
				aryr[r][numr[r]++].num = l;
			}
		}
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &l, &r);
			if (l == r && l > max)
			{
				max = l;
				temp = GREEN;
				idtemp = i;
			}
			aryg[l][numg[l]].id = i;
			aryg[l][numg[l]++].num = r;
			if (l != r)
			{
				aryg[r][numg[r]].id = i;
				aryg[r][numg[r]++].num = l;
			}
		}
		nextr = nextg = n;
		if (temp == RED)
		{
			nextr--;
			usedr[idtemp] = 1;
		}
		else
		{
			nextg--;
			usedg[idtemp] = 1;
		}
		lside = rside = max;
		final = 0;
		dfs(1 - temp, 0);
		if (cas)
		{
			printf("\n");
		}
		cas = 1;
		if (final == 0)
		{
			printf("No players can win\n");
		}
		else if (final == 3)
		{
			printf("Both players can win\n");
		}
		else if (final & (1 << RED))
		{
			printf("Only player Red can win\n");
		}
		else
		{
			printf("Only player Green can win\n");
		}
	}
	return 0;
}

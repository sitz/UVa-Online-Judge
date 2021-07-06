#include <bits/stdc++.h>

using namespace std;

int n;
int used[25];
int gx[25], gy[25], gi[25], go[25];
int imap[25][25], omap[25][25];
double gp[25];

int getdist(int x, int y)
{
	return x * x + y * y;
}

double ab(double now)
{
	if (now < 0)
	{
		return -now;
	}
	return now;
}

int zero(double now)
{
	return now < 1e-8;
}

int dfs(int now)
{
	int i;
	double speed;
	/*printf("GP %d: %.2lf\n", now, gp[now]);*/
	for (i = 0; i <= n; i++)
	{
		if (imap[now][i])
		{
			speed = -((gp[now] * gi[now]) / gi[i]);
			/*printf("imap %d => %d: %.3lf\n", now, i, speed);*/
			if (!used[i])
			{
				used[i] = 1;
				gp[i] = speed;
				if (dfs(i))
				{
					return 1;
				}
			}
			else
			{
				if (!zero(ab(gp[i] - speed)))
				{
					return 1;
				}
			}
		}
		if (omap[now][i])
		{
			speed = -((gp[now] * go[now]) / go[i]);
			/*printf("omap %d => %d: %.3lf\n", now, i, speed);*/
			if (!used[i])
			{
				used[i] = 1;
				gp[i] = speed;
				if (dfs(i))
				{
					return 1;
				}
			}
			else
			{
				if (!zero(ab(gp[i] - speed)))
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	int cas, i, j, f, dist, temp;
	cas = 0;
	while (scanf("%d%d%d%d%lf%d", &gx[0], &gy[0], &gi[0], &go[0], &gp[0], &n) == 6)
	{
		memset(imap, 0, sizeof(imap));
		memset(omap, 0, sizeof(omap));
		for (i = 1, f = 0; i <= n; i++)
		{
			scanf("%d%d%d%d", &gx[i], &gy[i], &gi[i], &go[i]);
			gp[i] = 0.0;
			if (!f)
			{
				for (j = 0; j < i; j++)
				{
					dist = getdist(gx[i] - gx[j], gy[i] - gy[j]);
					temp = go[i] + go[j];
					temp *= temp;
					if (dist == temp)
					{
						omap[i][j] = omap[j][i] = 1;
					}
					else if (dist < temp)
					{
						f = 1;
						break;
					}
					temp = gi[i] + gi[j];
					temp *= temp;
					if (dist == temp)
					{
						imap[i][j] = imap[j][i] = 1;
					}
					else if (dist < temp)
					{
						f = 1;
						break;
					}
				}
			}
		}
		printf("Simulation #%d\n", ++cas);
		if (f)
		{
			printf("Error -- Overlapping Gears\n\n");
		}
		else
		{
			memset(used, 0, sizeof(used));
			used[0] = 1;
			if (dfs(0))
			{
				printf("Error -- Conflicting Gear Rotation\n\n");
			}
			else
			{
				for (i = 1; i <= n; i++)
				{
					if (zero(ab(gp[i])))
					{
						printf("%2d: Warning -- Idle Gear\n", i);
					}
					else if (gp[i] > 0)
					{
						printf("%2d: R %.2lf\n", i, gp[i]);
					}
					else
					{
						printf("%2d: L %.2lf\n", i, -gp[i]);
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}

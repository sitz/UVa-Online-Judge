#include <bits/stdc++.h>

using namespace std;

int used[4];
int px[4], py[4];

int getgcd(int p, int q)
{
	if (p % q)
	{
		return getgcd(q, p % q);
	}
	return q;
}

int dfs(int depth, int sx, int sy)
{
	int i, x, y, stepx, stepy;
	if (sx < 0 || sy < 0)
	{
		return 0;
	}
	if (!sx || !sy)
	{
		return depth == 4;
	}
	for (i = 1; i < 4; i++)
	{
		if (!used[i])
		{
			used[i] = 1;
			if (!((px[i] * sy) % py[i]))
			{
				if (dfs(depth + 1, sx - (px[i] * sy) / py[i], sy))
				{
					return 1;
				}
			}
			if (!((py[i] * sx) % px[i]))
			{
				if (dfs(depth + 1, sx, sy - (py[i] * sx) / px[i]))
				{
					return 1;
				}
			}
			used[i] = 0;
		}
	}
	if (!used[0])
	{
		used[0] = 1;
		i = getgcd(px[0], py[0]);
		x = px[0] /= i;
		y = py[0] /= i;
		for (stepx = x, stepy = y; x <= sx && y <= sy; x += stepx, y += stepy)
		{
			if (x == sx)
			{
				if (dfs(depth + 1, sx, sy - y))
				{
					return 1;
				}
			}
			else if (y == sy)
			{
				if (dfs(depth + 1, sx - x, sy))
				{
					return 1;
				}
			}
			else
			{
				for (i = 1; i < 4; i++)
				{
					if (!used[i])
					{
						if (!((py[i] * x) % px[i]) && (py[i] * x) / px[i] == sy - y)
						{
							used[i] = 1;
							if (dfs(depth + 2, sx - x, sy))
							{
								return 1;
							}
							used[i] = 0;
						}
						if ((px[i] * y) % py[i] && (px[i] * y) / py[i] == sx - x)
						{
							used[i] = 1;
							if (dfs(depth + 2, sx, sy - y))
							{
								return 1;
							}
							used[i] = 0;
						}
					}
				}
			}
		}
		used[0] = 0;
	}
	return 0;
}

int main()
{
	int cas, i, sx, sy;
	cas = 0;
	while (scanf("%d%d", &sx, &sy) == 2)
	{
		if (!sx && !sy)
		{
			break;
		}
		for (i = 0; i < 4; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
		}
		memset(used, 0, sizeof(used));
		if (dfs(0, sx, sy))
		{
			printf("Set %d: Yes\n", ++cas);
		}
		else
		{
			printf("Set %d: No\n", ++cas);
		}
	}
	return 0;
}

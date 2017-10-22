#include <bits/stdc++.h>

using namespace std;

//#pragma comment(linker, "/STACK:16777216")

typedef long long LL;
const int N = 105;

int S, g[N][N], lx[N], ly[N], match[N], ans, slack[N];
int res[N];
bool fx[N], fy[N];

bool find(int x)
{
	fx[x] = 1;
	for (int y = 1; y <= S; ++y)
	{
		if (fy[y])
		{
			continue;
		}
		if (lx[x] + ly[y] == g[x][y])
		{
			fy[y] = 1;
			if (!match[y] || find(match[y]))
			{
				match[y] = x;
				res[x] = y;
				return 1;
			}
		}
		else
		{
			slack[y] = min(slack[y], lx[x] + ly[y] - g[x][y]);
		}
	}
	return 0;
}

void update()
{
	int delta = 1 << 30, i;
	for (i = 1; i <= S; ++i)
		if (!fy[i])
		{
			delta = min(delta, slack[i]);
		}
	for (i = 1; i <= S; ++i)
	{
		if (fx[i])
		{
			lx[i] -= delta;
		}
		if (fy[i])
		{
			ly[i] += delta;
		}
		slack[i] -= delta;
	}
}

void Kuhn_Munkras()
{
	int i, j;
	for (i = 1; i <= S; ++i)
	{
		match[i] = lx[i] = ly[i] = 0;
		for (j = 1; j <= S; ++j)
		{
			lx[i] = max(lx[i], g[i][j]);
		}
	}
	for (i = 1; i <= S; ++i)
	{
		while (1)
		{
			for (j = 1; j <= S; ++j)
			{
				fx[j] = fy[j] = 0, slack[j] = 1 << 30;
			}
			if (find(i))
			{
				break;
			}
			else
			{
				update();
			}
		}
	}
}
void work()
{
	int i, j, x;
	for (i = 1; i <= S; ++i)
		for (j = 1; j <= S; ++j)
		{
			g[i][j] = -1 << 29;
		}
	for (i = 1; i <= S; ++i)
	{
		while (scanf("%d", &x), x)
		{
			scanf("%d", &j);
			g[i][x] = max(g[i][x], -j);
		}
	}
	Kuhn_Munkras();
	int res = 0;
	for (i = 1; i <= S; ++i)
	{
		if (g[match[i]][i] == -1 << 29)
		{
			break;
		}
		res += g[match[i]][i];
	}
	if (i <= S)
	{
		puts("N");
	}
	else
	{
		printf("%d\n", -res);
	}
}

int main()
{
	while (scanf("%d", &S), S)
	{
		work();
	}
	return 0;
}

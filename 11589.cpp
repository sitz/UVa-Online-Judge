#include <bits/stdc++.h>

using namespace std;

const int N = 2505;
int n, q, h1, m1, h2, m2, time1, time2, vis[20][20][20][105], tim;
struct Point
{
	int x, y, z;
	Point() {}
	void scan()
	{
		scanf("%d%d%d", &x, &y, &z);
	}
} p, s, e, v;

bool judge(int x, int y, int z, int ti)
{
	int i, j, k, l;
	for (i = x; i < x + v.x; i++)
	{
		for (j = y; j < y + v.y; j++)
		{
			for (k = z; k < z + v.z; k++)
			{
				for (l = ti; l < ti + tim; l++)
				{
					if (vis[i][j][k][l])
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}

int solve()
{
	int ans = 0, i, j, k, t;
	for (i = 1; i <= p.x - v.x + 1; i++)
	{
		for (j = 1; j <= p.y - v.y + 1; j++)
		{
			for (k = 1; k <= p.z - v.z + 1; k++)
			{
				for (t = 1; t <= 96 - tim + 1; t++)
				{
					if (judge(i, j, k, t))
					{
						ans++;
					}
				}
			}
		}
	}
	return ans;
}

int main()
{
	int cas = 0;
	while (~scanf("%d%d%d%d%d", &n, &p.x, &p.y, &p.z, &q) && n)
	{
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++)
		{
			s.scan();
			e.scan();
			scanf("%d:%d%d:%d", &h1, &m1, &h2, &m2);
			time1 = (h1 * 60 + m1) / 15;
			time2 = (h2 * 60 + m2) / 15;
			for (int x = s.x + 1; x <= e.x; x++)
			{
				for (int y = s.y + 1; y <= e.y; y++)
				{
					for (int z = s.z + 1; z <= e.z; z++)
					{
						for (int t = time1 + 1; t <= time2; t++)
						{
							vis[x][y][z][t] = 1;
						}
					}
				}
			}
		}
		printf("3D World %d:\n", ++cas);
		while (q--)
		{
			v.scan();
			scanf("%d:%d", &h1, &m1);
			tim = (h1 * 60 + m1) / 15;
			int ans = solve();
			if (ans)
			{
				printf("%d safe place(s) found\n", ans);
			}
			else
			{
				printf("No safe place(s) found\n");
			}
		}
	}
	return 0;
}

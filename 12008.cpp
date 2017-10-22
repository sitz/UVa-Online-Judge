#include <bits/stdc++.h>

using namespace std;

int ab(int x)
{
	if (x < 0)
	{
		return -x;
	}
	return x;
}
int main()
{
	int cas, r, c, sr, sc, dr, dc, cc = 0, u, t, v, d;
	scanf("%d", &cas);
	while (cas--)
	{
		scanf("%d%d%d%d%d%d", &r, &c, &sr, &sc, &dr, &dc);
		printf("Case %d: ", ++cc);
		if (r < c)
		{
			swap(r, c);
			swap(sr, sc), swap(dr, dc);
		}
		if (ab(sr + dr + sc + dc) % 2)
		{
			printf("impossible\n");
		}
		else if (sr == dr && sc == dc)
		{
			printf("0\n");
		}
		else if (ab(sr - dr) == ab(sc - dc))
		{
			printf("1\n");
		}
		else if (ab(sr - dr) < ab(sc - dc))
		{
			printf("2\n");
		}
		else
		{
			if (c == 1)
			{
				printf("impossible\n");
			}
			else
			{
				if (sr < dr)
				{
					d = sc - sr + dr - dc;
					t = (d - 1) / (2 * c - 2);
					u = (d - 1) % (2 * c - 2);
					if (u < 2 * (c - dc))
					{
						u = 1;
					}
					else
					{
						u = 2;
					}
					//printf("#%d\n",2*t+u+1);
					v = 2 * t + u + 1;
					d = dr + dc - sr - sc;
					t = (d - 1) / (2 * c - 2);
					u = (d - 1) % (2 * c - 2);
					if (u < 2 * (dc - 1))
					{
						u = 1;
					}
					else
					{
						u = 2;
					}
					//printf("#%d\n",2*t+u+1);
					if (v > 2 * t + u + 1)
					{
						v = 2 * t + u + 1;
					}
				}
				else
				{
					d = sr - sc + dc - dr;
					t = (d - 1) / (2 * c - 2);
					u = (d - 1) % (2 * c - 2);
					if (u < 2 * (dc - 1))
					{
						u = 1;
					}
					else
					{
						u = 2;
					}
					//printf("#%d\n",2*t+u+1);
					v = 2 * t + u + 1;
					d = sr + sc - dr - dc;
					t = (d - 1) / (2 * c - 2);
					u = (d - 1) % (2 * c - 2);
					if (u < 2 * (c - dc))
					{
						u = 1;
					}
					else
					{
						u = 2;
					}
					//printf("#%d\n",2*t+u+1);
					if (v > 2 * t + u + 1)
					{
						v = 2 * t + u + 1;
					}
				}
				printf("%d\n", v);
			}
		}
	}
	return 0;
}

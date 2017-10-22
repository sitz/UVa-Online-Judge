#include <bits/stdc++.h>

using namespace std;

#define N 100005

struct line
{
	int x, y;
} a[N], b[N];
int n;
bool cmp(struct line x, struct line y)
{
	if (x.x != y.x)
	{
		return x.x < y.x;
	}
	return x.y < y.y;
}
void rota(int sin, int cos)
{
	int x2, y2, i, x, y;
	x2 = a[0].x, y2 = a[0].y;
	for (i = 1; i < n; i++)
	{
		x = x2 + (a[i].x - x2) * cos - (a[i].y - y2) * sin;
		y = y2 + (a[i].x - x2) * sin + (a[i].y - y2) * cos;
		a[i].x = x, a[i].y = y;
	}
}
int main()
{
	int t, i, j, xx, yy, k, flag;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &a[i].x, &a[i].y);
		}
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &b[i].x, &b[i].y);
		}
		for (k = 0; k < 4; k++)
		{
			flag = 0;
			rota(1, 0);
			sort(a, a + n, cmp);
			//printf("\\\\//\n");
			//for(i=0;i<n;i++)
			//printf("%d %d\n",a[i].x,a[i].y);
			//printf("\n\n");
			sort(b, b + n, cmp);
			//printf("aaa\n");
			//for(i=0;i<n;i++)
			//printf("%d %d\n",b[i].x,b[i].y);
			//printf("\n\n");
			xx = b[0].x - a[0].x;
			yy = b[0].y - a[0].y;
			for (i = 1; i < n; i++)
			{
				if (a[i].x + xx != b[i].x || a[i].y + yy != b[i].y)
				{
					flag = 1;
					break;
				}
			}
			if (!flag)
			{
				break;
			}
		}
		if (!flag)
		{
			printf("MATCHED\n");
		}
		else
		{
			printf("NOT MATCHED\n");
		}
	}
	return 0;
}

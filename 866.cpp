#include <bits/stdc++.h>

using namespace std;

#define N 105

int px1[N], px2[N], py1[N], py2[N];

int diff(int p, int q)
{
	return (p > 0 && q < 0) || (p < 0 && q > 0);
}

int cross(int x1, int y1, int x2, int y2)
{
	return x1 * y2 - x2 * y1;
}

int intersect(int p, int q)
{
	int vx1, vx2, vx3, vx4, vx5, vx6, vy1, vy2, vy3, vy4, vy5, vy6;
	vx1 = px2[p] - px1[p];
	vy1 = py2[p] - py1[p];
	vx2 = px1[q] - px1[p];
	vy2 = py1[q] - py1[p];
	vx3 = px2[q] - px1[p];
	vy3 = py2[q] - py1[p];
	vx4 = px2[q] - px1[q];
	vy4 = py2[q] - py1[q];
	vx5 = px1[p] - px1[q];
	vy5 = py1[p] - py1[q];
	vx6 = px2[p] - px1[q];
	vy6 = py2[p] - py1[q];
	return diff(cross(vx1, vy1, vx2, vy2), cross(vx1, vy1, vx3, vy3)) && diff(cross(vx4, vy4, vx5, vy5), cross(vx4, vy4, vx6, vy6));
}

int main()
{
	int count, n, i, j, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i = 0, ans = 0; i < n; i++)
		{
			scanf("%d%d%d%d", &px1[i], &py1[i], &px2[i], &py2[i]);
			ans++;
			for (j = 0; j < i; j++)
			{
				if (intersect(i, j))
				{
					ans += 2;
				}
			}
		}
		printf("%d\n", ans);
		if (count)
		{
			printf("\n");
		}
	}
	return 0;
}

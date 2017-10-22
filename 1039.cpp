#include <bits/stdc++.h>

using namespace std;

inline int max(int a, int b)
{
	return a > b ? a : b;
}

struct nodes
{
	double x, y;
} tower[100], city[100];
double eps = 1e-6;
int B, C, R, Q, mat[100][100], oo;

int belong(double x, double y)
{
	double d = oo, dis;
	int cho;
	for (int i = 0; i < B; i++)
		if ((dis = hypot(x - tower[i].x, y - tower[i].y)) < d)
		{
			d = dis;
			cho = i;
		}
	return cho;
}

int main()
{
	int tcas = 1;
	int i, j, k;
	while (scanf("%d%d%d%d", &B, &C, &R, &Q) != EOF)
	{
		if (B == 0 && C == 0 && R == 0 && Q == 0)
		{
			break;
		}
		memset(mat, 0x3f, sizeof(mat));
		oo = mat[0][0];
		for (i = 0; i < B; i++)
		{
			scanf("%lf%lf", &tower[i].x, &tower[i].y);
		}
		for (i = 0; i < C; i++)
		{
			scanf("%lf%lf", &city[i].x, &city[i].y);
		}
		for (i = 0; i < R; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			a--, b--;
			double x = city[b].x - city[a].x,
						 y = city[b].y - city[a].y;
			double L = 0, R = 1, mid;
			int ori = belong(city[a].x + L * x,
											 city[a].y + L * y);
			int to = belong(city[b].x, city[b].y);
			int res = 0;
			while (L + eps < R)
			{
				if (ori == to)
				{
					break;
				}
				else
				{
					res++;
				}
				double left = L, right = R;
				int ans;
				while (left + eps < right)
				{
					mid = (left + right) / 2;// binary search
					int tmp = belong(city[a].x + mid * x,
													 city[a].y + mid * y);
					if (tmp != ori)
					{
						right = mid - eps, ans = tmp;
					}
					else
					{
						left = mid + eps;
					}
				}
				L = right + eps;
				ori = ans;
			}
			mat[a][b] = mat[b][a] = res;
		}
		for (i = 0; i < C; i++)
		{
			mat[i][i] = 0;
		}
		for (k = 0; k < C; k++)
		{
			for (i = 0; i < C; i++)
			{
				for (j = 0; j < C; j++)
				{
					mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
				}
			}
		}
		printf("Case %d:\n", tcas++);
		for (i = 0; i < Q; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			a--, b--;
			if (mat[a][b] == oo)
			{
				printf("Impossible\n");
			}
			else
			{
				printf("%d\n", mat[a][b]);
			}
		}
	}
	return 0;
}

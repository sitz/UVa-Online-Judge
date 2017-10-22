#include <bits/stdc++.h>

using namespace std;

#define _USE_MATH_DEFINES// exposes constants, eg. M_PI
const double PI = M_PI;
#define MAXBODIES (50)
typedef struct
{
	double x, y;
} point;
typedef struct
{
	int r, t;
} planet;
planet table[MAXBODIES + 1];
point res[MAXBODIES + 1];
void solve(int n, int t)
{
	int centre = 0;
	for (int i = 1; i <= n; i++)
	{
		double angle = ((t % table[i].t) * 2 * PI) / (double)table[i].t;
		res[i].x = table[i].r * cos(angle) + res[i - 1].x;
		res[i].y = table[i].r * sin(angle) + res[i - 1].y;
		centre += table[i].r;
	}
	for (int i = 1; i < n; i++)
	{
		printf("%.4lf ", sqrt(res[i].x * res[i].x + res[i].y * res[i].y));
	}
	printf("%.4lf\n", sqrt(res[n].x * res[n].x + res[n].y * res[n].y));
}
int main()
{
	int n, t;
	while (scanf("%d %d", &n, &t) != EOF)
	{
		res[0].x = 0.0;
		res[0].y = 0.0;
		int ri, ti;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d", &ri, &ti);
			table[i].r = ri;
			table[i].t = ti;
		}
		solve(n, t);
		if (!feof(stdin))
		{
			//printf("\n");
		}
	}
	fflush(stdout);
	return 0;
}

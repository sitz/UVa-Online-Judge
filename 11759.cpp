#include <bits/stdc++.h>

using namespace std;

#define eps 1e-8
#define zero(x) (((x) > 0 ? (x) : -(x)) < eps)
#define maxn 2000
int Q[maxn];
struct point
{
	double x, y;
} tmp[maxn], P[600][1100];
double xmult(point p1, point p2, point p0)
{
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
bool cmp(point a, point b)
{
	return a.y < b.y || (a.y == b.y && a.x < b.x);
}
void out(point a)
{
	printf("--%lf %lf\n", a.x, a.y);
}
void calc(int &N, point P[])
{
	int i, cnt;
	sort(P, P + N, cmp);
	cnt = 0;
	Q[cnt++] = 0;
	for (i = 1; i < N;)
		if (cnt == 1 || xmult(P[Q[cnt - 1]], P[i], P[Q[cnt - 2]]) >= 0)
		{
			Q[cnt++] = i++;
		}
		else
		{
			cnt--;
		}
	int top = cnt;
	for (i = N - 2; i >= 0;)
		if (cnt == top || xmult(P[Q[cnt - 1]], P[i], P[Q[cnt - 2]]) >= 0)
		{
			Q[cnt++] = i--;
		}
		else
		{
			cnt--;
		}
	cnt--;
	for (i = 0; i < cnt; i++)
	{
		tmp[i] = P[Q[i]];
	}
	N = cnt;
	memcpy(P, tmp, N * sizeof(tmp[0]));
	return;
}
int N, sz[1000];
bool isin(int out, int in)
{
	int i, j;
	for (i = 0; i < sz[out]; i++)
	{
		j = (i + 1) % sz[out];
		if (xmult(P[out][j], P[in][0], P[out][i]) < 0)
		{
			break;
		}
	}
	if (i < sz[out])
	{
		return 0;
	}
	return 1;
}
int mat[600][600], in[600];
double len[600];
#define sqr(x) (x) * (x)
double calcdis(point a, point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
int main()
{
	int i, j, tcas = 1;
	while (scanf("%d", &N) && N)
	{
		for (i = 0; i < N; i++)
		{
			scanf("%d", &sz[i]);
			for (j = 0; j < sz[i]; j++)
			{
				scanf("%lf%lf", &P[i][j].x, &P[i][j].y);
			}
			calc(sz[i], P[i]);
			len[i] = 0;
			for (j = 0; j < sz[i]; j++)
			{
				len[i] += calcdis(P[i][j], P[i][(j + 1) % sz[i]]);
			}
			/*for (j=0;j<sz[i];j++)
			    printf("%lf -- %lf\n",P[i][j].x,P[i][j].y);*/
		}
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
			{
				mat[i][j] = -1;
			}
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
				if (i != j)
				{
					if (mat[i][j] == -1 && isin(i, j))
					{
						//  printf("%d --> %d\n",j,i);
						// out(P[j][0]),out(P[i][0]);
						mat[i][j] = 1;
						mat[j][i] = 0;
						in[j]++;
					}
				}
				else
				{
					mat[i][j] = 0;
				}
		}
		int L = 0, R = 0, Q[1000], f[1000];
		for (i = 0; i < N; i++)
			if (in[i] == 0)
			{
				f[i] = 0;
				Q[R++] = i;
			}
			else
			{
				f[i] = -1;
			}
		printf("Case %d:\n", tcas++);
		printf("Total Number of Communities %d\n", R);
		double ans0 = 0, ans1 = 0;
		while (L < R)
		{
			int now = Q[L++];
			// printf("%d %d\n",now,f[now]);
			//  out(P[now][0]);
			if (f[now])
			{
				ans1 += len[now] * 50;
			}
			else
			{
				ans0 += len[now] * 100;
			}
			for (i = 0; i < N; i++)
				if (mat[now][i] == 1)
				{
					in[i]--;
					if (in[i] == 0)
					{
						f[i] = 1 - f[now];
						Q[R++] = i;
					}
				}
		}
		printf("Total Cost:\nSteel Fence: %.9lf  Million Yuan\nWooden Fence: %.9lf Million Yuan\n\n", ans0 / 1000000, ans1 / 1000000);
	}
}

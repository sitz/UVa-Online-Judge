#include <bits/stdc++.h>

using namespace std;

// Simplex algorithm on augmented matrix a of dimension (m+1)x(n+1)
// returns 1 if feasible, 0 if not feasible, -1 if unbounded
// returns solution in b[] in original var order, max(f) in ret
// form: maximize sum_j(a_mj*x_j)-a_mn s.t. sum_j(a_ij*x_j)<=a_in
// in standard form.
// To convert into standard form:
// 1. if exists equality constraint, then replace by both >= and <=
// 2. if variable x doesn't have nonnegativity constraint, then replace by
// difference of 2 variables like x1-x2, where x1>=0, x2>=0
// 3. for a>=b constraints, convert to -a<=-b
// note: watch out for -0.0 in the solution, algorithm may cycle
// eps = 1e-7 may give wrong answer, 1e-10 is better

const double inf = 1e100;
const double eps = 1e-10;

#define maxm 500
#define maxn 500

void pivot(int m, int n, double a[maxm][maxn], int B[maxm], int N[maxn], int r, int c)
{
	int i, j;
	swap(N[c], B[r]);
	a[r][c] = 1 / a[r][c];
	for (j = 0; j <= n; j++)
		if (j != c)
		{
			a[r][j] *= a[r][c];
		}
	for (i = 0; i <= m; i++)
		if (i != r)
		{
			for (j = 0; j <= n; j++)
				if (j != c)
				{
					a[i][j] -= a[i][c] * a[r][j];
				}
			a[i][c] = -a[i][c] * a[r][c];
		}
}
int feasible(int m, int n, double a[maxm][maxn], int B[maxm], int N[maxn])
{
	int r, c, i;
	double p, v;
	while (1)
	{
		for (p = inf, i = 0; i < m; i++)
			if (a[i][n] < p)
			{
				p = a[r = i][n];
			}
		if (p > -eps)
		{
			return 1;
		}
		for (p = 0, i = 0; i < n; i++)
			if (a[r][i] < p)
			{
				p = a[r][c = i];
			}
		if (p > -eps)
		{
			return 0;
		}
		p = a[r][n] / a[r][c];
		for (i = r + 1; i < m; i++)
			if (a[i][c] > eps)
			{
				v = a[i][n] / a[i][c];
				if (v < p)
				{
					r = i, p = v;
				}
			}
		pivot(m, n, a, B, N, r, c);
	}
}
int simplex(int m, int n, double a[maxm][maxn], double b[maxn], double &ret)
{
	int B[maxm], N[maxn], r, c, i;
	double p, v;
	for (i = 0; i < n; i++)
	{
		N[i] = i;
	}
	for (i = 0; i < m; i++)
	{
		B[i] = n + i;
	}
	if (!feasible(m, n, a, B, N))
	{
		return 0;
	}
	while (1)
	{
		for (p = 0, i = 0; i < n; i++)
			if (a[m][i] > p)
			{
				p = a[m][c = i];
			}
		if (p < eps)
		{
			for (i = 0; i < n; i++)
				if (N[i] < n)
				{
					b[N[i]] = 0;
				}
			for (i = 0; i < m; i++)
				if (B[i] < n)
				{
					b[B[i]] = a[i][n];
				}
			ret = -a[m][n];
			return 1;
		}
		for (p = inf, i = 0; i < m; i++)
			if (a[i][c] > eps)
			{
				v = a[i][n] / a[i][c];
				if (v < p)
				{
					p = v, r = i;
				}
			}
		if (p == inf)
		{
			return -1;
		}
		pivot(m, n, a, B, N, r, c);
	}
}

int n, c, d, F, e, Q, mat[20][20], qx[300], qy[300];

void IN(int a, int l, int h)
{
	assert(l <= a && a <= h);
}

void input()
{
	int i, j;
	scanf("%d%d%d%d%d%d", &n, &c, &d, &F, &e, &Q);
	IN(n, 1, 12);
	IN(c, 0, 100);
	IN(d, 0, 100);
	IN(F, -10, 10);
	IN(e, 0, 5);
	IN(Q, 1, n * n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			scanf("%d", &mat[i][j]);
			IN(mat[i][j], -10, 10);
		}
	for (i = 0; i < Q; i++)
	{
		scanf("%d%d", &qx[i], &qy[i]);
		IN(qx[i], 1, n);
		IN(qy[i], 1, n);
		qx[i]--;
		qy[i]--;
	}
}

#define I_ID(r, c) (c) * (n) + (r)
#define D_ID(r, c) n *n + I_ID(r, c)

double A[maxm][maxn], B[maxn];

double process()
{
	memset(A, 0, sizeof(A));
	int neq = 2 * Q, nvar = 2 * n * n;
	int cureq = 0;
	double ret;
	int i, j, status;
	for (i = 0; i < Q; i++)
	{
		A[cureq][nvar] = e + (2 * n - 1) * F;
		A[cureq + 1][nvar] = e - (2 * n - 1) * F;
		for (j = 0; j < n; j++)//row
		{
			A[cureq][nvar] -= mat[j][qy[i]];
			A[cureq + 1][nvar] += mat[j][qy[i]];
			A[cureq][I_ID(j, qy[i])] = 1;
			A[cureq][D_ID(j, qy[i])] = -1;
			A[cureq + 1][I_ID(j, qy[i])] = -1;
			A[cureq + 1][D_ID(j, qy[i])] = 1;
		}
		for (j = 0; j < n; j++)
			if (j != qy[i])//col
			{
				A[cureq][nvar] -= mat[qx[i]][j];
				A[cureq + 1][nvar] += mat[qx[i]][j];
				A[cureq][I_ID(qx[i], j)] = 1;
				A[cureq][D_ID(qx[i], j)] = -1;
				A[cureq + 1][I_ID(qx[i], j)] = -1;
				A[cureq + 1][D_ID(qx[i], j)] = 1;
			}
		cureq += 2;
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			A[cureq][I_ID(i, j)] = -c;
			A[cureq][D_ID(i, j)] = -d;
		}
	status = simplex(neq, nvar, A, B, ret);
	assert(status == 1);
	return -ret;
}

int main()
{
	int T;
	double ans;
	scanf("%d", &T);
	IN(T, 1, 100);
	while (T--)
	{
		input();
		ans = process();
		printf("%.5lf\n", ans);
	}
	return 0;
}

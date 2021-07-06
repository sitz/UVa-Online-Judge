#include <bits/stdc++.h>

using namespace std;

typedef double Matrix[4][4];

const double eps = 1e-10;

int dcmp(double a)
{
	return fabs(a) < eps ? 0 : (a < 0 ? -1 : 1);
}

const int MAXN = 110;

int n;
double a[MAXN], b[MAXN], c[MAXN];

bool gauss_jordan(Matrix a)
{
	int n = 3;
	for (int i = 0; i < n; i++)
	{
		int r = i;
		for (int j = i + 1; j < n; j++)
		{
			if (fabs(a[j][i]) > fabs(a[r][i]))
			{
				r = j;
			}
		}
		if (dcmp(a[r][i]) == 0)
		{
			continue;
		}

		if (r != i)
		{
			for (int j = 0; j <= n; j++)
			{
				swap(a[r][j], a[i][j]);
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				for (int k = n; k >= i; k--)
				{
					a[j][k] -= a[j][i] / a[i][i] * a[i][k];
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		int xs = 0;
		for (int j = 0; j < n; j++)
		{
			if (dcmp(a[i][j]))
			{
				xs++;
			}
		}
		if (xs == 0)
		{
			if (dcmp(a[i][n]))
			{
				return false;
			}
			continue;
		}
		if (xs == 1)
		{
			if (dcmp(a[i][n] / a[i][i]) == -1)
			{
				return false;
			}
			else
			{
				continue;
			}
		}
		if (dcmp(a[i][n]) == -1)
		{
			for (int j = 0; j <= n; j++)
			{
				a[i][j] *= -1;
			}
		}
		bool Pos = false;
		for (int j = 0; j < n; j++)
		{
			if (dcmp(a[i][j]) == 1)
			{
				Pos = true;
				break;
			}
		}
		if (!Pos)
		{
			return false;
		}
	}
	return true;
}

bool solve(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			for (int k = j; k < n; k++)
			{
				Matrix now, hi;
				now[0][0] = a[i];
				now[0][1] = a[j];
				now[0][2] = a[k];
				now[0][3] = a[n];
				now[1][0] = b[i];
				now[1][1] = b[j];
				now[1][2] = b[k];
				now[1][3] = b[n];
				now[2][0] = c[i];
				now[2][1] = c[j];
				now[2][2] = c[k];
				now[2][3] = c[n];

				bool ok = true;
				int ord[] = {0, 1, 2};
				do
				{
					for (int ii = 0; ii < 3; ii++)
					{
						int jj = ord[ii];
						for (int kk = 0; kk < 3; kk++)
						{
							hi[kk][jj] = now[kk][ii];
						}
					}
					for (int ii = 0; ii < 3; ii++)
					{
						hi[ii][3] = now[ii][3];
					}
					if (!gauss_jordan(hi))
					{
						ok = false;
						break;
					}
				} while (next_permutation(ord, ord + 3));
				if (ok)
				{
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	int n, t = 0;
	while (scanf("%d", &n) == 1 && n)
	{
		if (t)
		{
			printf("\n");
		}
		for (int i = 0; i <= n; i++)
		{
			scanf("%lf%lf%lf", &a[i],&b[i],&c[i]);
		}
		printf("Mixture %d\n%s\n", ++t, solve(n) ? "Possible" : "Impossible");
	}

	return 0;
}

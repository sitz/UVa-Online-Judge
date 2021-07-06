#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

const int N_MAX = 2;

template <class T>
void mul(int n, const T A[N_MAX][N_MAX], const T x[N_MAX], T y[N_MAX])
{
	static T z[N_MAX];
	rep(i, n)
	{
		z[i] = 0;
		rep(j, n) z[i] += A[i][j] * x[j];
	}
	rep(i, n) y[i] = z[i];
}

template <class T>
void mul(int n, const T A[N_MAX][N_MAX], const T B[N_MAX][N_MAX], T C[N_MAX][N_MAX])
{
	static T tmp[N_MAX][N_MAX];
	rep(i, n) rep(j, n)
	{
		tmp[i][j] = 0;
		rep(k, n) tmp[i][j] += A[i][k] * B[k][j];
	}
	rep(i, n) rep(j, n) C[i][j] = tmp[i][j];
}

template <class T>
void pow(int n, const T A[N_MAX][N_MAX], int m, T B[N_MAX][N_MAX])
{
	static T tmp[N_MAX][N_MAX];
	rep(i, n) rep(j, n)
	{
		tmp[i][j] = A[i][j];
		B[i][j] = (i == j ? 1 : 0);
	}
	for (int t = 0; m > 0; t++)
	{
		if (m & (1LL << t))
		{
			mul(n, B, tmp, B);
			m -= 1LL << t;
		}
		mul(n, tmp, tmp, tmp);
	}
}

double solve()
{
	double a0, a1, b0, b1;
	int n;
	scanf("%lf%lf%lf%lf%d", &a0, &a1, &b0, &b1, &n);
	complex<double> a(a0, a1), b(b0, b1);
	complex<double> A[2][2] = {{1 / sqrt(2), 1 / sqrt(2)}, {1 / sqrt(2), -1 / sqrt(2)}}, v[2] = {a, b};
	pow(2, A, n, A);
	mul(2, A, v, v);
	return norm(v[0]);
}

int main()
{
	int T;
	scanf("%d ", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		printf("Case %d: %.6f\n", cas, solve());
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define REP(i, a) FOR(i, 0, a)
#define EPS 1e-9
#define inf (1LL << 30)
#define LL long long
#define ULL unsigned long long
#define abs(x) (((x) < 0) ? (-(x)) : (x))
#define all(x) (x).begin(), (x).end()
#define ms(x, a) memset((x), (a), sizeof(x))
#define VI vector<int>
#define VS vector<string>
#define VC vector<char>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define CI(x) scanf(" %d", &x)
#define CL(x) scanf(" %lld", &x)
#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)
#define PI 2 * acos(0.0)
#define MOD 10007
int K;
template <int d>
class Matrix
{
public:
	int dx;
	LL v[d][d];
	Matrix()
	{
		ms(v, 0);
	}
	Matrix<d> mul(const Matrix<d> &b)
	{
		Matrix<d> r;
		for (int k = 0; k < K; ++k)
		{
			for (int i = 0; i < K; ++i)
			{
				for (int j = 0; j < K; ++j)
					r.v[i][j] = ((r.v[i][j] % MOD) + ((v[i][k] % MOD) * (b.v[k][j] % MOD))) % MOD;
			}
		}
		return r;
	}
	Matrix<d> pow(ULL p)
	{
		//  cerr << p << endl;
		Matrix<d> r, b = *this;
		for (int i = 0; i < d; ++i)
			r.v[i][i] = 1;
		for (; p; p /= 2)
		{
			//  cerr << p << endl;
			if (p % 2)
				r = r.mul(b);
			b = b.mul(b);
		}
		return r;
	}
};
int a, b, c;
LL dp[1005][105];
LL f(int n, int k)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	LL &res = dp[n][k];
	if (res != -1)
		return res;
	res = 0;
	for (int i = 2; i <= k; i++)
	{
		if (i > n)
			break;
		//cerr << n << "  " <<  i << endl;
		res = (res + f(n - i, k)) % MOD;
	}
	//cerr << n-k-1 << endl;
	return res;
}
Matrix<101> A, B;
int main()
{
	ms(dp, -1);
	int t, cas = 0, k;
	LL n;
	scanf(" %d", &t);
	while (t--)
	{
		scanf(" %lld %d", &n, &k);
		K = k;
		LL res = 0;
		if (n < 200)
		{
			res = 0;
			REP(i, k)
			res = (res + f(n - i, k)) % MOD;
		}
		else
		{
			ms(A.v, 0);
			ms(B.v, 0);
			for (int i = 0; i < k; i++)
			{
				B.v[i][0] = f(k - i, k) % MOD;
			}
			A.v[0][0] = 0;
			for (int i = 1; i < k; i++)
			{
				A.v[0][i] = 1;
			}
			for (int i = 1; i < k; i++)
			{
				A.v[i][i - 1] = 1;
			}
			A = A.pow(n - k);
			A = A.mul(B);
			res = 0;
			REP(i, k)
			{
				res = (res + A.v[i][0]) % MOD;
			}
		}
		printf("Case %d: %lld\n", ++cas, (res * 2) % MOD);
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)((x).size())
#define rep(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define clr(x) memset((x), 0, sizeof(x))

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
const int maxn = 66;
const ll mod = 1000000007;
int s;
struct Mat
{
	ll mat[maxn][maxn];
	void clear()
	{
		memset(mat, 0, sizeof(mat));
	}
} A, ans, E, M;
Mat operator*(Mat a, Mat b)
{
	Mat c;
	memset(c.mat, 0, sizeof(c.mat));
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			//if (a.mat[i][j]==0)continue;
			for (int k = 0; k < s; k++)
			{
				c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
				c.mat[i][j] %= mod;
			}
		}
	}
	return c;
}
Mat operator+(Mat a, Mat b)
{
	Mat c;
	memset(c.mat, 0, sizeof(Mat));
	for (int i = 0; i < s; i++)
		for (int j = 0; j < s; j++)
			c.mat[i][j] = (a.mat[i][j] + b.mat[i][j]) % mod;
	return c;
}
Mat operator^(Mat A, int x)//Ã³??Ã¨??Î¼Ã­?Ã³Ã Â¨o?
{
	Mat c = E;
	for (; x; x >>= 1)
	{
		if (x & 1)
			c = c * A;
		A = A * A;
	}
	return c;
}
ll a[66], aa[66];
int main()
{
	int i, j, k, n;
	for (i = 0; i < maxn; i++)
		E.mat[i][i] = 1;
	int cas;
	scanf("%d", &cas);
	while (cas--)
	{
		int d;
		scanf("%d%d", &n, &d);
		for (i = 0; i < n; i++)
			scanf("%lld", a + i);
		s = n;
		A.clear();
		for (i = 1; i < n; i++)
		{
			for (j = 0; j < i; j++)
			{
				A.mat[i][j] = 1;
			}
		}
		for (i = 0; i < n; i++)
		{
			A.mat[i][n - 1] = 1;
		}
		/*
		for (i=0;i<s;i++)
		{
			for (j=0;j<s;j++)
			{
				printf("%d ",A.mat[i][j]);
			}
			puts("");
		}
		*/
		ans = (A ^ (d - 1));
		memset(aa, 0, sizeof(aa));
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				aa[i] += a[j] * ans.mat[i][j];
				aa[i] %= mod;
			}
			printf("%lld", aa[i]);
			if (i == n - 1)
				puts("");
			else
				putchar(' ');
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

//*************************OUTPUT*************************
#ifdef WIN32
#define INT64 "%I64d"
#define UINT64 "%I64u"
#else
#define INT64 "%lld"
#define UINT64 "%llu"
#endif

//**************************CONSTANT***********************
#define INF 0x7f7f7f7f
#define eps 1e-8
#define PI acos(-1.)
#define PI2 asin(1.);
typedef long long LL;
//typedef __int64 LL;   //codeforces
typedef unsigned int ui;
typedef unsigned long long ui64;
#define MP make_pair
typedef vector<int> VI;
typedef pair<int, int> PII;
#define pb push_back
#define mp make_pair

//***************************SENTENCE************************
#define CL(a, b) memset(a, b, sizeof(a))
#define sqr(a, b) sqrt((double)(a) * (a) + (double)(b) * (b))
#define sqr3(a, b, c) sqrt((double)(a) * (a) + (double)(b) * (b) + (double)(c) * (c))

//****************************FUNCTION************************
template <typename T>
double DIS(T va, T vb)
{
	return sqr(va.x - vb.x, va.y - vb.y);
}
template <class T>
inline T INTEGER_LEN(T v)
{
	int len = 1;
	while (v /= 10)
	{
		++len;
	}
	return len;
}
template <typename T>
inline T square(T va, T vb)
{
	return va * va + vb * vb;
}

// aply for the memory of the stack
//#pragma comment (linker, "/STACK:1024000000,1024000000")
//end

#define CY 1005
const int mod = 1000000007;

int dp[CY][CY];
int N, K;

int dfs(int n, int k)
{
	if (n == 0 || n == k)
	{
		return dp[n][k] = 0;
	}
	if (k == 0)
	{
		return dp[n][k] = 1;
	}
	if (~dp[n][k])
	{
		return dp[n][k];
	}
	dp[n][k] = 0;
	dp[n][k] = (int)((LL) - ~k * dfs(n - 1, k) % mod + (LL)(n - k) * dfs(n - 1, k - 1) % mod) % mod;
	return dp[n][k];
}

int main()
{
	memset(dp, -1, sizeof(dp));
	while (2 == scanf("%d%d", &N, &K))
	{
		printf("%d\n", dfs(N, K));
	}
	return 0;
}

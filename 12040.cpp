#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", cas++);
#define EPS 1e-9
#define MAX 100010
#define ll long long
#define INF (1 << 30)
#define pii pair<int, int>
#define MP make_pair
#define mod 10000007
int xx[] = {1, 1, 0, -1, -1, -1, 0, 1}, yy[] = {0, 1, 1, 1, 0, -1, -1, -1};//eight direction

int n, lim;
string inp;
int pi[105];
int dp[105][105];

void prefix_func()
{
	int i, j, k;
	pi[0] = 0;
	k = 0;
	for (i = 1; i < SZ(inp); i++)
	{
		while (k > 0 && inp[i] != inp[k])
		{
			k = pi[k - 1];
		}
		if (inp[i] == inp[k])
		{
			k++;
		}
		pi[i] = k;
	}
	return;
}

int rec(int now, int k)
{
	int i, j;
	int &ret = dp[now][k];
	if (ret != -1)
	{
		return ret;
	}
	if (k == lim)
	{
		return 0;
	}
	if (now == n)
	{
		return 1;
	}
	ret = 0;
	int st = 0, nowk;
	if (now == 0 && n > 1)
	{
		st = 1;
	}
	for (i = st; i <= 9; i++)
	{
		nowk = k;
		while (nowk > 0 && i != (inp[nowk] - '0'))
		{
			nowk = pi[nowk - 1];
		}
		if (i == (inp[nowk] - '0'))
		{
			nowk++;
		}
		ret = (ret + rec(now + 1, nowk)) % mod;
	}
	return ret;
}

int main()
{
	int t, cas = 1;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d ", &n);
		cin >> inp;
		lim = SZ(inp);
		prefix_func();
		memset(dp, -1, sizeof dp);
		int ans = rec(0, 0);
		cout << ans << endl;
	}
	return 0;
}

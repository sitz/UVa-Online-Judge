#include <bits/stdc++.h>

using namespace std;

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-8
#define pi acos(-1.0)

typedef unsigned long long ll;
const int maxn = 100 + 10;
int num[maxn], n, d, one, zero;
int ot[maxn], zt[maxn];
ll dp[maxn][maxn];
pair<int, int> v[maxn];
bool check(int x, int y, int b)
{
	if (b)
	{
		return zt[x + 1] + d >= ot[y + 1];
	}
	return ot[y + 1] + d >= zt[x + 1];
}
void cal(ll &minv, ll &maxv)
{
	for (int i = 0; i < n; ++i)
	{
		if (num[i] == 0)
		{
			int t = i;
			v[i] = make_pair(t, 0);
		}
		else
		{
			int t = max(i, i + d);
			v[i] = make_pair(t, 1);
		}
	}
	sort(v, v + n);
	minv = 0;
	for (int i = 0; i < n; ++i)
	{
		if (v[i].second)
		{
			minv |= 1ULL << (n - i - 1ULL);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (num[i] == 1)
		{
			int t = i;
			v[i] = make_pair(t, -1);
		}
		else
		{
			int t = max(i, i + d);
			v[i] = make_pair(t, 0);
		}
	}
	sort(v, v + n);
	maxv = 0;
	for (int i = 0; i < n; ++i)
	{
		if (v[i].second)
		{
			maxv |= 1ULL << (n - i - 1ULL);
		}
	}
}
int main()
{
	//    freopen("in.txt","r",stdin);
	//    freopen("out.txt","w",stdout);
	ll m;
	int tcase = 0;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		cin >> d >> m;
		//        scanf("%d%lld",&d,&m);
		//        cout<<n<<d<<m<<endl;
		for (int i = n - 1; i >= 0; --i)
		{
			num[n - i - 1] = (m >> i) & 1;
		}
		one = 0, zero = 0;
		ot[0] = zt[0] = 0;
		for (int i = 0; i < n; ++i)
		{
			if (num[i])
			{
				ot[++one] = i;
			}
			else
			{
				zt[++zero] = i;
			}
		}
		ot[one + 1] = zt[zero + 1] = inf;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 0; i <= n - one; ++i)
			for (int j = 0; j <= one; ++j)
			{
				if (dp[i][j] == 0)
				{
					continue;
				}
				if (check(i, j, 0))
				{
					dp[i + 1][j] += dp[i][j];
				}
				if (check(i, j, 1))
				{
					dp[i][j + 1] += dp[i][j];
				}
			}
		ll minv, maxv;
		cal(minv, maxv);
		cout << "Case " << ++tcase << ": ";
		cout << dp[n - one][one] << " " << minv << " " << maxv << endl;
		//        printf("Case %d: %lld %lld %lld\n",++tcase,,minv,maxv);
	}
	return 0;
}

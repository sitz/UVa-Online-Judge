#include <bits/stdc++.h>

using namespace std;

#define eps 1e-8
#define M 800010
#define N 20011
#define ll long long
#define inf 0x3f3f3f3f
#define ull unsigned long long

int son[M][26], pre[M], len[M];
int t, tail;
void init()
{
	len[0] = t = tail = 0;
	memset(son[0], 0, sizeof(son[0]));
	pre[0] = -1;
}

void add(int x)
{
	int p = tail, np = ++t;
	tail = np;
	memset(son[t], 0, sizeof(son[t]));
	len[np] = len[p] + 1;
	while (p != -1 && !son[p][x])
	{
		son[p][x] = np, p = pre[p];
	}
	if (p == -1)
	{
		pre[np] = 0;
	}
	else
	{
		int q = son[p][x];
		if (len[p] + 1 == len[q])
		{
			pre[np] = q;
		}
		else
		{
			int nq = ++t;
			memcpy(son[nq], son[q], sizeof(son[q]));
			len[nq] = len[p] + 1;
			pre[nq] = pre[q];
			pre[q] = pre[np] = nq;
			while (p != -1 && son[p][x] == q)
			{
				son[p][x] = nq, p = pre[p];
			}
		}
	}
}

ll getCnt()
{
	ll ans = 0;
	int p;
	for (int i = 1; i <= t; ++i)
	{
		p = i;
		ans += len[p] - len[pre[p]];
	}
	return ans;
}
char str[M];
int k;
ll dp[M];

int main()
{
	int T, cas = 0;
	scanf("%d", &T);
	ll one, two, more, ans;
	while (T--)
	{
		scanf("%s%d", str, &k);
		init();
		for (int i = 0; str[i]; ++i)
		{
			add(str[i] - 'a');
		}
		one = getCnt();
		dp[1] = one;
		//cout<<dp[1]<<endl;
		for (int j = 2; j <= 4; ++j)
		{
			for (int i = 0; str[i]; ++i)
			{
				add(str[i] - 'a');
			}
			dp[j] = getCnt();
		}
		if (k == 1)
		{
			ans = one;
		}
		else if (k <= 3)
		{
			ans = dp[k];
		}
		else
		{
			ans = dp[3];
			ans += (k - 3LL) * (dp[3] - dp[2]);
		}
		printf("Case %d: ", ++cas);
		cout << ans << endl;
	}
	return 0;
}

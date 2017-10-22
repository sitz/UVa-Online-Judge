#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll x;
char ch[26], ts[20020];
int pre[20020];
int pos[26];
int n, m;
int f[20020][510];
int w(int i, int j)
{
	int ret = pre[j];
	if (i != 0)
		ret -= pre[i - 1];
	return ret * i;
}
struct QQ
{
	int k, b;
} que[20020];

int main()
{
	int T;
	scanf("%d", &T);
	int cas = 1;
	while (T--)
	{
		scanf("%s", ch);
		for (int i = 0; i < 26; i++)
			pos[ch[i] - 'a'] = i;
		scanf("%d%s", &m, ts);
		n = strlen(ts);
		int ans = 0;

		for (int i = 0; i < n; i++)
		{
			ans += (i - pos[ts[i] - 'a']) * pos[ts[i] - 'a'];
			if (i == 0)
				pre[i] = pos[ts[i] - 'a'];
			else
				pre[i] = pre[i - 1] + pos[ts[i] - 'a'];
		}
		for (int j = 0; j <= m; j++)
			for (int i = 0; i <= n; i++)
				f[i][j] = -2000000000;
		for (int i = 0; i < n; i++)
		{
			f[i][1] = 0;
		}
		for (int j = 2; j <= m; j++)
		{
			int st, ed;
			st = ed = 1;
			for (int i = j - 1; i < n; i++)
			{
				que[0].k = i;
				que[0].b = f[i - 1][j - 1] - i * pre[i - 1];
				while (st < ed && (que[0].b - que[ed - 1].b) * (que[ed - 1].k - que[ed - 2].k) > (que[0].k - que[ed - 1].k) * (que[ed - 1].b - que[ed - 2].b))
					ed--;
				que[ed].k = que[0].k;
				que[ed].b = que[0].b;
				ed++;
				while (st < ed - 1 && que[st].k * pre[i] + que[st].b < que[st + 1].k * pre[i] + que[st + 1].b)
					st++;
				f[i][j] = que[st].k * pre[i] + que[st].b;
			}
		}
		ans -= f[n - 1][m];
		printf("Case %d: %d\n", cas++, ans);
	}
	return 0;
}

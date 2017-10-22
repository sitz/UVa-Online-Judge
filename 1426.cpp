#include <bits/stdc++.h>

using namespace std;

#define maxn 40000 + 10
#define LL long long

bool vis[maxn];
LL pri[20000], yinzi[20000], cou[20000], ans[2000000], all, ansnum;
LL n, r;
LL extEculid(LL a, LL b, LL &x, LL &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	LL g = extEculid(b, a % b, x, y);
	LL tmp = x;
	x = y;
	y = tmp - a / b * y;
	return g;
}
void bfs(int num, LL cur)
{
	int i, j, k;
	if (num == all)
	{
		LL p, q;
		//printf("cur=%lld,",cur);
		LL g = extEculid(cur, n / cur, p, q);
		if (2 * r % g)
		{
			return;
		}
		p *= -2 * r / g;
		q *= 2 * r / g;
		for (int h = 0; h < g; h++)
		{
			ans[ansnum++] = ((r + p * cur) % n + n) % n;
			p += n / cur / g;
		}
		return;
	}
	bfs(num + 1, cur);
	for (i = 0; i < cou[num]; i++)
	{
		cur *= yinzi[num];
		bfs(num + 1, cur);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int i, j, k, v = 1;
	LL x;
	for (i = 2; i * i < maxn; i++)
		if (!vis[i])
			for (j = i * i; j < maxn; j += i)
			{
				vis[j] = 1;
			}
	for (i = 2, k = 0; i < maxn; i++)
		if (!vis[i])
		{
			pri[k++] = i;
		}
	while (cin >> x >> n >> r && (x + n + r))
	{
		printf("Case %d:", v++);
		LL num = n;
		for (i = 0, k = 0; pri[i] * pri[i] <= n; i++)
			if (num % pri[i] == 0)
			{
				yinzi[k] = pri[i];
				cou[k] = 0;
				while (num % pri[i] == 0)
				{
					cou[k]++;
					num /= pri[i];
				}
				k++;
				if (num == 1)
				{
					break;
				}
			}
		if (num > 1)
		{
			yinzi[k] = num;
			cou[k++] = 1;
		}
		//for(i=0;i<k;i++)
		//    printf("ans[k]=%lld,",yinzi[i]);
		all = k;
		ans[0] = r;
		ansnum = 1;
		bfs(0, 1);
		sort(ans, ans + ansnum);
		//printf("ansnum=%d\n",ansnum);
		int len = unique(ans, ans + ansnum) - ans;
		for (i = 0; i < len; i++)
		{
			printf(" %lld", ans[i]);
		}
		puts("");
	}
	return 0;
}

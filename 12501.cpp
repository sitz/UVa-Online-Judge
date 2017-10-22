#include <bits/stdc++.h>

using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
typedef long long ll;

const int maxn = 100005;
ll sum1[maxn << 2], sum2[maxn << 2], late[maxn << 2];

void up(int rt)
{
	int ls = rt << 1, rs = rt << 1 | 1;
	sum1[rt] = sum1[ls] + sum1[rs];
	sum2[rt] = sum2[ls] + sum2[rs];
}

void down(int rt, int l, int r)
{
	if (late[rt])
	{
		int ls = rt << 1, rs = rt << 1 | 1;
		int m = (l + r) >> 1;
		late[ls] += late[rt];
		late[rs] += late[rt];
		sum1[ls] += late[rt] * (m - l + 1);
		sum1[rs] += late[rt] * (r - m);
		sum2[ls] += late[rt] * ((ll)l + m) * (m - l + 1) / 2;
		sum2[rs] += late[rt] * ((ll)m + 1 + r) * (r - m) / 2;
		late[rt] = 0;
	}
}

void build(int l, int r, int rt)
{
	late[rt] = 0;
	if (l == r)
	{
		sum1[rt] = 100;
		sum2[rt] = 100 * l;
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	up(rt);
}

void update(int L, int R, ll key, int l, int r, int rt)
{
	if (L <= l && r <= R)
	{
		late[rt] += key;
		sum1[rt] += key * (r - l + 1);
		sum2[rt] += key * ((ll)l + r) * (r - l + 1) / 2;
		return;
	}
	int m = (l + r) >> 1;
	down(rt, l, r);
	if (L <= m)
		update(L, R, key, lson);
	if (m < R)
		update(L, R, key, rson);
	up(rt);
}

ll query(int L, int R, int l, int r, int rt)
{
	if (L <= l && r <= R)
		return sum2[rt] - sum1[rt] * (L - 1);
	int m = (l + r) >> 1;
	ll ret = 0;
	down(rt, l, r);
	if (L <= m)
		ret += query(L, R, lson);
	if (m < R)
		ret += query(L, R, rson);
	return ret;
}

int main()
{
	int T;
	char op[10];
	scanf("%d", &T);
	for (int cc = 1; cc <= T; cc++)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		build(1, n, 1);
		printf("Case %d:\n", cc);
		while (m--)
		{
			scanf("%s", op);
			if (!strcmp(op, "query"))
			{
				int a, b;
				scanf("%d%d", &a, &b);
				printf("%lld\n", query(a, b, 1, n, 1));
			}
			else
			{
				int a, b;
				ll c;
				scanf("%d%d%lld", &a, &b, &c);
				update(a, b, c, 1, n, 1);
			}
		}
	}
	return 0;
}

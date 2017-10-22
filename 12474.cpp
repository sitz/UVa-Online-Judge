#include <bits/stdc++.h>

using namespace std;

#define lowbit(x) (x & (-x))
#define LL long long
#define ULL unsigned long long
#define maxn 2000
#define msize 30000
#define mod 1000000009ll
#define CC(m, what) memset(m, what, sizeof(m))
#define inf 0x7f7f7f7f
#define eps 1e-12
#define lson l, mid, fa << 1
#define rson mid + 1, r, fa << 1 | 1
#define pi acos(-1.0)
#define keytree (ch[ch[root][1]][0])

template <class Z>
inline bool checkmax(Z &a, Z b)
{
	if (a == -1 || a < b)
	{
		a = b;
		return true;
	}
	return false;
}
template <class Z>
inline bool checkmin(Z &a, Z b)
{
	if (a == -1 || a > b)
	{
		a = b;
		return true;
	}
	return false;
}

map<LL, LL> p;

LL dfs(LL x)
{
	if (x == 0)
	{
		return 0;
	}
	if (p[x])
	{
		return p[x];
	}
	if (x & 1)
	{
		return p[x] = x / 2 + 2 * dfs(x / 2);
	}
	else
	{
		return p[x] = (x - 1) / 2 + dfs(x / 2) + dfs(x / 2 - 1);
	}
}

int main()
{
	int cas;
	int i, j, k = 1;
	LL n;
	p.clear();
	scanf("%d", &cas);
	while (cas--)
	{
		cin >> n;
		printf("Case %d: %lld\n", k++, dfs(n));
	}
	return 0;
}

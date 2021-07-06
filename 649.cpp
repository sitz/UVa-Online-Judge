#include <bits/stdc++.h>

using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define INF 0x3f3f3f3f
const int N = 30;
int n, m, a, b, know[N], ans, s;

inline int bitcount(int x)
{
	return x == 0 ? 0 : (bitcount(x / 2) + (x & 1));
}

inline int cal(int s, int Min, int s1)
{
	int ans = 0;
	int ss = (((1 << n) - 1) ^ s);
	int s2 = n - s1;
	if (abs(s1 - s2) > 1)
	{
		return -1;
	}
	for (int i = 0; i < n; i++)
	{
		if (s & (1 << i))
		{
			int kno = (know[i] & s);
			int lone = s1 - bitcount(kno);
			ans = max(ans, lone);
		}
		if (ss & (1 << i))
		{
			int kno = (know[i] & ss);
			int lone = s2 - bitcount(kno);
			ans = max(ans, lone);
		}
		if (ans > Min)
		{
			return -1;
		}
	}
	return ans;
}

void dfs(int num, int ss, int d)
{
	if ((n - d) + num < n / 2)
	{
		return;
	}
	if (num >= n / 2)
	{
		int t = cal(ss, ans, num);
		if (t != -1)
		{
			if (ans > t)
			{
				ans = t;
				s = ss;
			}
		}
		return;
	}
	dfs(num + 1, ss | (1 << d), d + 1);
	dfs(num, ss, d + 1);
}

inline void solve()
{
	ans = INF;
	int i;
	dfs(0, 0, 0);
	printf("%d\n", ans);
	printf("%d", bitcount(s));
	for (i = 0; i < n; i++)
		if (s & (1 << i))
		{
			printf(" %d", i + 1);
		}
	printf("\n");
	int ss = (((1 << n) - 1) ^ s);
	printf("%d", bitcount(ss));
	for (i = 0; i < n; i++)
		if (ss & (1 << i))
		{
			printf(" %d", i + 1);
		}
	printf("\n");
}

int main()
{
	int bo = 0;
	while (~scanf("%d", &n))
	{
		if (bo++)
		{
			printf("\n");
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &a, &m);
			a--;
			know[a] = (1 << a);
			while (m--)
			{
				scanf("%d", &b);
				b--;
				know[a] = (know[a] | (1 << b));
			}
		}
		solve();
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long hash_t;
const int maxn = 2e5 + 11;
const int seed = 131;
int T, N;
char s[maxn];
hash_t val[maxn], base[maxn];
void pre()
{
	base[0] = 1;
	for (int i = 1; i < maxn; ++i)
	{
		base[i] = base[i - 1] * seed;
	}
}
void build(char s[], int N)
{
	val[N] = 0;
	for (int i = N - 1; i >= 0; --i)
	{
		val[i] = val[i + 1] + s[i] * base[N - i - 1];
	}
}
inline hash_t getInteval(int beg, int len)
{
	return (val[beg] - val[beg + len]) * base[beg + len];
}
inline bool cmp(int beg1, int len1, int beg2, int len2)
{
	int l = 1, r = min(len1, len2) + 1;
	while (l < r)
	{
		int m = (l + r) >> 1;
		if (getInteval(beg1, m) == getInteval(beg2, m))
		{
			l = m + 1;
		}
		else
		{
			r = m;
		}
	}
	return s[beg1 + l - 1] < s[beg2 + l - 1];
}
int main()
{
	pre();
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%s", &N, s);
		for (int i = N; i < 2 * N; ++i)
		{
			s[i] = s[i - N];
		}
		s[2 * N] = '\0';
		build(s, 2 * N);
		int ans = 0;
		for (int i = 1; i < N; ++i)
		{
			if (cmp(i, N, ans, N))
			{
				ans = i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, b, a) for (int i = (b); i >= (a); --i)
#define clr(a, x) memset(a, x, sizeof(a))
#define eb emplace_back

const int maxn = 100 * 100 * 100 + 5;
int sum[maxn];

inline int lowbit(int x) { return x & (-x); }

void add(int p, int x)
{
	while (p < maxn)
	{
		sum[p] += x;
		p += lowbit(p);
	}
}

int query(int l, int r)
{
	if (l > r)
	{
		return 0;
	}
	int ret = 0;
	--l;
	while (r >= 1)
	{
		ret += sum[r];
		r -= lowbit(r);
	}
	while (l >= 1)
	{
		ret += sum[l];
		l -= lowbit(l);
	}
	return ret;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int M;
		scanf("%d", &M);
		clr(sum, 0);
		int zero_idx;
		int rev = 0;
		rep(i, 0, M * M * M)
		{
			int d;
			scanf("%d", &d);
			if (d == 0)
			{
				zero_idx = i;
			}
			else
			{
				rev += query(d + 1, M * M * M) % 2;
				add(d, 1);
				rev &= 1;
			}
		}
		if (~M & 1)
		{
			int z = zero_idx / (M * M);
			int y = zero_idx % (M * M) / M;
			int x = zero_idx % (M * M) % M;
			if (((M - 1) - z) % 2)
			{
				rev ^= 1;
			}
			if ((M - 1 - y) % 2)
			{
				rev ^= 1;
			}
		}
		puts(rev == 0 ? "Puzzle can be solved." : "Puzzle is unsolvable.");
	}
	return 0;
}

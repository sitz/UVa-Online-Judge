#include <bits/stdc++.h>

using namespace std;

#define MAXD 100010
#define INF 1000000000

int N, M, Q, tree[4 * MAXD], a[50], d[50], n;
char b[50];

int Min(int &x, int &y)
{
	return x < y ? x : y;
}
void init()
{
	int i, j;
	for (M = 1; M < N + 2; M <<= 1)
		;
	for (i = M; i < 2 * M; i++)
	{
		tree[i] = INF;
	}
	for (i = 0, j = M + 1; i < N; i++, j++)
	{
		scanf("%d", &tree[j]);
	}
	for (i = M - 1; i; i--)
	{
		tree[i] = Min(tree[2 * i], tree[2 * i + 1]);
	}
}
void change(int cur, int target)
{
	int i, j;
	cur += M;
	tree[cur] = target;
	for (; cur ^ 1; cur >>= 1)
	{
		tree[cur >> 1] = Min(tree[cur], tree[cur ^ 1]);
	}
}
void solve()
{
	int i, j, k, res, s, t;
	scanf("%s", b);
	if (b[0] == 's')
	{
		n = 0;
		for (i = 0; b[i]; i++)
		{
			if (isdigit(b[i]))
			{
				sscanf(&b[i], "%d", &a[n++]);
			}
			while (isdigit(b[i]))
			{
				i++;
			}
		}
		for (i = 0; i < n; i++)
		{
			if (i == n - 1)
			{
				d[i] = tree[M + a[0]];
			}
			else
			{
				d[i] = tree[M + a[i + 1]];
			}
		}
		for (i = 0; i < n; i++)
		{
			change(a[i], d[i]);
		}
	}
	else
	{
		sscanf(&b[6], "%d", &s);
		sscanf(strchr(b, ',') + 1, "%d", &t);
		res = INF;
		s = s - 1 + M;
		t = t + 1 + M;
		for (; s ^ t ^ 1; s >>= 1, t >>= 1)
		{
			if (~s & 1)
			{
				res = tree[s ^ 1] < res ? tree[s ^ 1] : res;
			}
			if (t & 1)
			{
				res = tree[t ^ 1] < res ? tree[t ^ 1] : res;
			}
		}
		printf("%d\n", res);
	}
}

int main()
{
	while (scanf("%d%d", &N, &Q) == 2)
	{
		init();
		for (int i = 0; i < Q; i++)
			solve();
	}
	return 0;
}

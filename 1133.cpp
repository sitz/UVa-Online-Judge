#include <bits/stdc++.h>

using namespace std;

#define maxn 3005

struct Segment
{
	int l, r, w;
	bool operator<(const Segment x) const
	{
		if (l == x.l)
			return r < x.r;
		return l < x.l;
	}
};
int n;
int dp[maxn];
Segment seg[maxn];
int search(int key)
{
	int low = key, high = n, mid = (low + high + 1) / 2;
	while (low < high)
	{
		if (seg[mid].l < seg[key].r)
			low = mid;
		else
			high = mid - 1;
		mid = (low + high + 1) / 2;
	}
	if (seg[mid].l <= seg[key].r)
		return mid + 1;
	return mid;
}

int main()
{
	int kase = 0;
	while (scanf("%d", &n) != EOF)
	{
		char str[100];
		if (kase)
			printf("\n");
		for (int i = 0; i < n; ++i)
		{
			scanf("%s%d%d%d", str, &seg[i].l, &seg[i].r, &seg[i].w);
			seg[i].r += seg[i].l;
		}
		memset(dp, 0, sizeof(dp));
		sort(seg, seg + n);
		for (int i = n - 1; i >= 0; --i)
		{
			int L = search(i);
			// cout<<i<<" "<<L<<endl;
			dp[i] = max(dp[i + 1], dp[L] + seg[i].w);
		}
		printf("%d\n", dp[0]);
		kase++;
	}
	return 0;
}

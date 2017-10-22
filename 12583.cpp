#include <bits/stdc++.h>

using namespace std;

#define Inf 2147483647
#define Pi acos(-1.0)
#define N 1000000
#define LL long long

inline LL Power(int b, int p)
{
	LL ret = 1;
	for (int i = 1; i <= p; i++)
	{
		ret *= b;
	}
	return ret;
}

#define F(i, a, b) for (int i = (a); i < (b); i++)
#define Fs(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Fe(i, x) for (typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define Set(a, s) memset(a, s, sizeof(a))
#define max(a, b) (a < b ? b : a)
#define min(a, b) (a > b ? b : a)

int main()
{
	int testCases;
	scanf("%d", &testCases);
	int cases = 0;
	while (testCases--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		char str[1000];
		scanf("%s", str);
		int vis[26 + 5];
		Set(vis, 0);
		int ret = 0;
		for (int i = 0; i < n; i++)
		{
			if (vis[str[i] - 'A'])
			{
				ret++;
			}
			vis[str[i] - 'A']++;
			if (i - k >= 0)
			{
				vis[str[i - k] - 'A']--;
			}
		}
		printf("Case %d: %d\n", ++cases, ret);
	}
	return 0;
}

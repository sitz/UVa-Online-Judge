#include <bits/stdc++.h>

using namespace std;

#define DBLE 1e-8
#define PI 3.1415926535898
#define INF 1000000000
#define MAXN 2000010
#define MOD 1000000009
#define MP(x, y) make_pair((x), (y))

char str[MAXN];
int sum[MAXN];

int main()
{
	int ncase, l, b, n, p1, p2, tmp;
	long long ans;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%d%d%d", &l, &b, &n);
		memset(sum, 0, sizeof(sum));
		scanf("%s", &str[1]);
		for (int i = 1; i <= n; ++i)
			sum[i] = sum[i - 1] + (str[i] == '0' ? 1 : 0);
		p1 = 1, p2 = b;
		ans = 0;
		while (l != n)
		{
			if (p1 + l - 1 == n)
				break;
			while (sum[p2] - sum[p1] + l + p1 <= p2 && p1 < p2)
				++p1;
			ans += l;
			if (p1 + l - 1 == n)
				break;
			if (p2 - p1 + 1 == b)
				break;
			while (p2 < n && p2 - p1 + 1 < b)
				++p2, ++ans;
		}

		if (p2 == n && p1 + l - 1 == n)
			printf("%lld\n", ans);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
typedef long long LL;
LL eular_cnt[N];
LL eular_phi(LL n)
{
	LL res = n;
	for (LL i = 2; i * i <= n; i++)
		if (n % i == 0)
		{
			res = res / i * (i - 1);
			while (n % i == 0)
			{
				n /= i;
			}
		}
	if (n > 1)
	{
		res = res / n * (n - 1);
	}
	return res;
}
int main()
{
	int t, t_cnt = 0;
	scanf("%d", &t);
	while (t--)
	{
		LL n, q;
		vector<LL> data;
		scanf("%lld%lld", &n, &q);
		for (LL i = 1; i * i <= n; i++)
		{
			if (n % i)
			{
				continue;
			}
			data.push_back(i);
			if (n / i != i)
			{
				data.push_back(n / i);
			}
		}
		sort(data.begin(), data.end());
		for (int i = 0; i < (int)data.size(); i++)
		{
			eular_cnt[i + 1] = eular_cnt[i] + eular_phi(n / data[i]);
		}
		printf("Case %d\n", ++t_cnt);
		for (LL i = 0; i < q; i++)
		{
			LL x;
			scanf("%lld", &x);
			int pos = upper_bound(data.begin(), data.end(), x) - data.begin();
			printf("%lld\n", eular_cnt[pos]);
		}
	}
	return 0;
}

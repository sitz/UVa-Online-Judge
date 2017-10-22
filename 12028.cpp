#include <bits/stdc++.h>

using namespace std;

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long

#define For(i, a, b) for (int i = (a); i < (b); i++)
#define Fors(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Fore(it, x) for (typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define Set(a, s) memset(a, s, sizeof(a))

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

long long a[100000 + 10], accu_sum[100000 + 10];

int main()
{
	int testCase;
	scanf("%d", &testCase);
	int cases = 0;
	while (testCase--)
	{
		long long k, c, n;
		scanf("%lld %lld %lld %lld", &k, &c, &n, &a[0]);
		for (int i = 1; i < n; i++)
			a[i] = (k * a[i - 1] + c) % 1000007;
		sort(a, a + n);
		for (int i = 0; i < n; i++)
			accu_sum[i] = a[i];
		for (int i = 1; i < n; i++)
			accu_sum[i] += accu_sum[i - 1];
		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			long long first = a[i] * (n - i - 1);
			long long second = accu_sum[n - 1] - accu_sum[i];
			sum += abs(first - second);
		}
		printf("Case %d: %lld\n", ++cases, sum);
	}
	return 0;
}

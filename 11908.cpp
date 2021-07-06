#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/119/11908.html
// Runtime: 0.192s

// @BEGIN_OF_SOURCE_CODE

#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 200000
#define LL unsigned long long

struct floors
{
	int start;
	int end;
	int cost;
} a[30000 + 10];

int dp[N + 10];

bool cmp(floors p, floors q)
{
	if (p.start < q.start)
	{
		return true;
	}
	return false;
}

int main()
{
	int testCase;
	scanf("%d", &testCase);
	int cases = 0;
	while (testCase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d %d", &a[i].start, &a[i].end, &a[i].cost);
			a[i].start++;												 // starting floor
			a[i].end = a[i].end + a[i].start - 1;// ending floor
		}
		sort(a, a + n, cmp);
		memset(dp, 0, sizeof(dp));
		int ind = 0;
		int accu_cost = 0;
		for (int i = 1; i < N + 10; i++)
		{
			while (ind < n && a[ind].start == i)
			{
				int p = dp[i - 1] + a[ind].cost;
				if (dp[a[ind].end] < p)
				{
					dp[a[ind].end] = p;
				}
				ind++;
			}
			if (accu_cost < dp[i])
			{
				accu_cost = dp[i];
			}
			dp[i] = accu_cost;
		}
		int maxi = 0;
		for (int i = 0; i < N + 10; i++)
		{
			if (maxi < dp[i])
			{
				maxi = dp[i];
			}
		}
		printf("Case %d: %d\n", ++cases, maxi);
	}
	return 0;
}

// @END_OF_SOURCE_CODE

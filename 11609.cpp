#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/116/11609.html
// Runtime: 0.012s
// Tag: bigMod

// @BEGIN_OF_SOURCE_CODE

#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long

#define For(i, a, b) for (int i = (a); i < (b); i++)
#define Forv(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Set(a, s) memset(a, s, sizeof(a))

#define MOD 1000000007

LL bigMod(LL b, LL p)
{
	if (p == 0)
	{
		return 1;
	}
	if (p == 1)
	{
		return b;
	}
	if (p % 2 == 0)
	{
		LL x = bigMod(b, p / 2) % MOD;
		return (x * x) % MOD;
	}
	else
	{
		return (bigMod(b, p - 1) % MOD) * (b % MOD);
	}
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
		printf("Case #%d: ", ++cases);
		cout << ((bigMod(2, n - 1) * (n % MOD)) % MOD) << endl;
	}
	return 0;
}

// @END_OF_SOURCE_CODE

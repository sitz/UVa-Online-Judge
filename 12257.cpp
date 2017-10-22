#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int lst[1010][1010], super[1010], sons[1010];
long long pascal[1010][1010], resu[1010];

int cal(int boss)
{
	resu[boss] = 1;
	sons[boss] = 0;
	for (int i = 1; i <= lst[boss][0]; i++)
	{
		int cnt = lst[boss][i];
		cal(cnt);
		resu[boss] = (resu[boss] * resu[cnt]) % MOD;
		sons[boss] += sons[cnt] + 1;
	}
	int temp = sons[boss];
	for (int i = 1; i <= lst[boss][0]; i++)
	{
		int cnt = lst[boss][i];
		resu[boss] = (resu[boss] * pascal[temp][sons[cnt] + 1]) % MOD;
		temp -= sons[cnt] + 1;
	}
	return 0;
}

int main()
{
	int CASL;
	pascal[0][0] = 1;
	for (int i = 1; i <= 1000; i++)
	{
		pascal[i][0] = 1;
		for (int j = 1; j < i; j++)
		{
			pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]) % MOD;
		}
		pascal[i][i] = 1;
	}
	scanf("%d", &CASL);
	for (int CAS = 1; CAS <= CASL; CAS++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			lst[i][0] = 0;
			super[i] = 0;
		}
		for (int i = 1; i < n; i++)
		{
			int s, t;
			scanf("%d%d", &s, &t);
			super[t] = s;
			lst[s][++lst[s][0]] = t;
		}
		int boss;
		for (int i = 1; i <= n; i++)
		{
			if (super[i] == 0)
			{
				boss = i;
			}
		}
		cal(boss);
		printf("Case %d: %lld\n", CAS, resu[boss]);
	}
	return 0;
}

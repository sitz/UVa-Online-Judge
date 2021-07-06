#include <bits/stdc++.h>

using namespace std;

#define fr(a, b, c) for (int a = b; a < c; a++)
#define rp(a, b) fr(a, 0, b)
#define cl(a, b) memset(a, b, sizeof a)
#define MOD 100007

int N, M, cas = 1;
int dp[511][30], mark[511][30], passo;
int cnt[300], F[30];

int go(int i, int j)
{
	int &pd = dp[i][j];
	if (mark[i][j] == passo)
		return pd;
	mark[i][j] = passo;

	if (i == 0 && j >= M)
		return pd = 1;

	int ret = 0;
	if (i > 0)
		ret = (ret + i * go(i - 1, j)) % MOD;
	if (j < M)
		ret = (ret + F[j] * go(i + F[j] - 1, j + 1)) % MOD;
	return pd = ret;
}

char S[511], P[30];
int main()
{
	cl(mark, 0);
	passo = 0;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s%s", S, P);
		N = strlen(S);
		M = strlen(P);

		cl(cnt, 0);
		int total = 0;
		rp(i, N)
		{
			total++;
			cnt[S[i]]++;
		}
		rp(i, M)
		{
			total -= cnt[P[i]];
			F[i] = cnt[P[i]];
		}
		passo++;
		printf("Case %d: %d\n", cas++, go(total, 0));
	}
	return 0;
}
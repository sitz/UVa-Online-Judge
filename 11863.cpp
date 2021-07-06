#include <bits/stdc++.h>
using namespace std;
#define fr(a, b, c) for (int a = b; a < c; a++)
#define rp(a, b) fr(a, 0, b)

bool prime[101000];
void crivo()
{
	memset(prime, 0, sizeof prime);
	prime[2] = 1;
	for (int i = 3; i < 100010; i += 2)
		prime[i] = 1;
	for (int i = 3; i < 400; i += 2)
	{
		if (prime[i])
		{
			for (int j = i * i; j < 100010; j += i)
				prime[j] = 0;
		}
	}
}

int dp[110][110], x[110];
bool go(int i, int j)
{
	if (~dp[i][j])
		return dp[i][j];
	if (i >= j)
		return dp[i][j] = 0;

	bool vld = 0;
	int sum = 0;
	bool win = 0;
	for (int k = i; !win && k < j; k++)
	{
		if (x[k] == 42)
			vld = 1;
		sum += x[k];
		if (vld || (sum > 0 && prime[sum]))
			win |= !go(k + 1, j);
	}
	vld = 0;
	sum = 0;
	for (int k = j - 1; !win && k >= i; k--)
	{
		if (x[k] == 42)
			vld = 1;
		sum += x[k];
		if (vld || (sum > 0 && prime[sum]))
			win |= !go(i, k);
	}
	//printf("%d %d > %d\n", i, j, win);
	return dp[i][j] = win;
}

int main()
{
	crivo();
	int cas = 1;
	int T, N, K;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &K);
		rp(i, N) scanf("%d", &x[i]);
		memset(dp, -1, sizeof dp);
		printf("Case %d: ", cas++);
		if (go(0, N))
			printf("Soha\n");
		else
			printf("Tara\n");
	}
	return 0;
}
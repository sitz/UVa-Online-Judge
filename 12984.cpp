#include <bits/stdc++.h>

using namespace std;

// place sticks on both sides; can be as long as half the length
// thus, it becomes possible to select two dp[][]s that become half
// do not want the same number of decimal places
// dp[i][j] records the sum of the lengths becomes i and j becomes half; can get value
// note special case that you can take any stick

typedef long long LL;

int A[1000], V[1000];
LL DP[4001][3];

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		int N, L;
		scanf("%d%d", &N, &L);
		for (int Ni = 0; Ni < N; Ni++)
		{
			scanf("%d%d", &A[Ni], &V[Ni]);
		}
		fill(DP[0], DP[L * 2] + 3, 0);
		for (int Ni = 0; Ni < N; Ni++)
		{
			DP[L * 2][2] = max(DP[L * 2][2], (LL)V[Ni]);
		}
		for (int Ni = 0; Ni < N; Ni++)
		{
			for (int i = L * 2 - A[Ni] * 2; i >= 0; i--)
			{
				DP[i + A[Ni] * 2][2] = max(DP[i + A[Ni] * 2][2], DP[i][2] + V[Ni]);
			}
			for (int i = L * 2 - A[Ni]; i >= 0; i--)
			{
				DP[i + A[Ni]][2] = max(DP[i + A[Ni]][2], DP[i][1] + V[Ni]);
			}
			for (int i = L * 2 - A[Ni] * 2; i >= 0; i--)
			{
				DP[i + A[Ni] * 2][1] = max(DP[i + A[Ni] * 2][1], DP[i][1] + V[Ni]);
			}
			for (int i = L * 2 - A[Ni]; i >= 0; i--)
			{
				DP[i + A[Ni]][1] = max(DP[i + A[Ni]][1], DP[i][0] + V[Ni]);
			}
			for (int i = L * 2 - A[Ni] * 2; i >= 0; i--)
			{
				DP[i + A[Ni] * 2][0] = max(DP[i + A[Ni] * 2][0], DP[i][0] + V[Ni]);
			}
		}
		printf("Case #%d: %lld\n", t, DP[L * 2][2]);
	}
	return 0;
}

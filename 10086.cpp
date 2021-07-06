#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int main()
{
	ios::sync_with_stdio(false);
	int T, S, N, M[35], X[35][35], tot, tmp, prev, O[35];
	pair<long long, int> dp[35][305];
	while (cin >> T >> S && (T + S))
	{
		cin >> N;
		for (int i = 0; i < N; i += 1)
		{
			cin >> M[i];
			X[i][0] = 0;
			for (int j = 0; j < M[i]; j += 1)
			{
				cin >> X[i][j + 1];
			}
			for (int j = 1; j <= M[i]; j += 1)
			{
				cin >> tmp;
				X[i][M[i] - j] += tmp;
			}
		}
		tot = 0;
		dp[0][0] = make_pair(0, 0);
		for (int n = 1; n <= N; n += 1)
		{
			for (int i = 0; i <= min(T, tot + M[n - 1]); i += 1)
			{
				dp[n][i].X = 100000000;
				for (int j = max(i - M[n - 1], 0); j <= min(i, tot); j += 1)
				{
					if (dp[n][i].X > dp[n - 1][j].X + X[n - 1][i - j])
					{
						dp[n][i].X = dp[n - 1][j].X + X[n - 1][i - j];
						dp[n][i].Y = i - j;
					}
				}
			}
			tot += M[n - 1];
		}
		cout << dp[N][T].X << '\n';
		prev = T;
		for (int i = N; i >= 1; i -= 1)
		{
			O[i] = dp[i][prev].Y;
			prev -= dp[i][prev].Y;
		}
		for (int i = 1; i < N; i += 1)
		{
			cout << O[i] << ' ';
		}
		cout << O[N] << "\n\n";
	}
	return 0;
}

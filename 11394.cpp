#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define REP(i, a, b) for ((i) = a; (i) < (int)(b); ++(i))
#define FILL(a, v) memset(a, v, sizeof(a))
const int MAXN = 18, SIZE = 17;
int i, j, k, m, n;
ll bc[MAXN][MAXN], dp[SIZE][SIZE][5];
char input[MAXN];
inline int value(char ch)
{
	if (isalpha(ch))
	{
		return 10 + ch - 'A';
	}
	return ch - '0';
}
inline ll binomial_coefficient(int a, int b)
{
	int n = max(a, b);
	int m = min(a, b);
	for (i = 0; i <= n; i++)
	{
		bc[i][0] = 1;
	}
	for (j = 0; j <= n; j++)
	{
		bc[j][j] = 1;
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j < i; j++)
		{
			bc[i][j] = bc[i - 1][j - 1] + bc[i - 1][j];
		}
	return bc[n][m];
}
int main()
{
	FILL(bc, 0);
	binomial_coefficient(MAXN, MAXN);
	while (cin >> input)
	{
		if (!strcmp(input, "#"))
		{
			break;
		}
		FILL(dp, 0);
		REP(i, 0, SIZE)
		REP(j, 0, 5)
		dp[i][0][j] = 0;
		REP(i, 0, SIZE)
		REP(j, 0, 5)
		dp[0][i][j] = 0;
		dp[0][0][0] = 1;
		REP(i, 0, SIZE)
		REP(j, 0, SIZE)
		REP(k, 0, 5)
		{
			// count number of copies of 'i'
			int num_copies = 0;
			REP(m, 0, strlen(input))
			{
				if (value(input[m]) == i)
				{
					num_copies++;
				}
			}
			REP(n, 0, num_copies + 1)
			{
				if (j >= n && i > 0)
				{
					ll part1 = dp[i - 1][j - n][(1000000 + k - n * i) % 5];
					ll part2 = bc[j][n];
					ll sum = part1 * part2;
					dp[i][j][k] += sum;
				}
			}
		}
		ll answer = 0;
		REP(i, 0, SIZE)
		{
			//cerr << "i: " << i << " " << dp[SIZE-1][i][0] << endl;
			answer += dp[SIZE - 1][i][0];
		}
		cout << (answer - 1) << endl;
	}
}

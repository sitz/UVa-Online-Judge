#include <bits/stdc++.h>

using namespace std;

// Probability of winning the game at deuce, if each game is won with probability p
double pr_2dif(double p)
{
	return p * p / (1 - 2 * p * (1 - p));
}

// Probability that the first player wins a game if
//  a) he wins each point with probability p
//  b) he needs to win 'num' >= 2 points with a difference of at least 2
//  c) the winning probability at score num-num is pr_tie
// This can also be used for sets.
double pr_win(double p, int num, double pr_tie)
{
	double f[num + 3][num + 3];
	fill(&f[0][0], &f[num + 3][0], -1);
	// Winning states
	for (int i = num; i <= num + 2; ++i)
		for (int j = 0; j <= i - 2; ++j)
		{
			f[i][j] = 1;
			f[j][i] = 0;
		}
	// Fill remaining states using dynamic programming
	f[num][num] = pr_tie;
	f[num][num + 1] = f[num - 1][num] = p * f[num][num];
	f[num + 1][num] = f[num][num - 1] = p + (1 - p) * f[num][num];
	for (int i = num - 1; i >= 0; --i)
		for (int j = num - 1; j >= 0; --j)
		{
			f[i][j] = p * f[i + 1][j] + (1 - p) * f[i][j + 1];
		}
	return f[0][0];
}

double pr_game(double p)
{
	return pr_win(p, 4, pr_2dif(p));
}

double pr_set(double p)
{
	double pr_tiebreak = pr_win(p, 7, pr_2dif(p));
	return pr_win(pr_game(p), 6, pr_tiebreak);
}

double pr_match(double p)
{
	double q = pr_set(p);
	return q * q + q * (1 - q) * q + (1 - q) * q * q;
}

int main()
{
	double p;
	while (scanf("%lf", &p), p >= 0)
	{
		printf("%.11lf %.11lf %.11lf\n", pr_game(p), pr_set(p), pr_match(p));
	}
	return 0;
}

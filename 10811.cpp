#include <bits/stdc++.h>

using namespace std;

#define MAX_MONEY 20000

double prob[2][MAX_MONEY][10], probWin;
int min_[31][10], max_[31][10], n, k, l, m;

void play(int round)
{
	for (int i = 0; i < 10; i++)
	{
		min_[round][i] = min_[round - 1][i];
	}
	for (int i = 0; i < 10; i++)
	{
		max_[round][i] = max_[round - 1][i];
	}
	int n = round & 1, p = 1 - n;
	memset(prob[n], 0, sizeof(prob[n]));
	for (int bet = 0; (1 << bet) <= l; bet++)
	{
		int from = min_[round - 1][bet], to = max_[round - 1][bet], b = (1 << bet);
		for (int i = from; i < to; i++)
		{
			prob[n][i + 3 * b][0] += 1.0 / 14 * prob[p][i][bet];
		}
		for (int i = from; i < to; i++)
		{
			prob[n][i + 2 * b][0] += 1.0 / 14 * prob[p][i][bet];
		}
		for (int i = from; i < to; i++)
		{
			prob[n][i + 1 * b][0] += 2.0 / 14 * prob[p][i][bet];
		}
		if (from + 3 * b < min_[round][0])
		{
			min_[round][0] = from + 3 * b;
		}
		if (to + 3 * b > max_[round][0])
		{
			max_[round][0] = to + 3 * b;
		}
		// consider we lose: 10/14
		if (2 * b > l)
		{
			// if house limit is reached, go back to 1 dollar
			for (int i = from; i < to; i++)
			{
				prob[n][i - b][0] += 10.0 / 14 * prob[p][i][bet];
			}
			if (from - b < min_[round][0])
			{
				min_[round][0] = from - b;
			}
			if (to - b > max_[round][0])
			{
				max_[round][0] = to - b;
			}
		}
		else
		{
			// else: double!
			for (int i = from; i < to; i++)
			{
				prob[n][i - b][bet + 1] += 10.0 / 14 * prob[p][i][bet];
			}
			if (from - b < min_[round][bet + 1])
			{
				min_[round][bet + 1] = from - b;
			}
			if (to - b > max_[round][bet + 1])
			{
				max_[round][bet + 1] = to - b;
			}
		}
	}
	if (round >= k)
	{
		for (int i = MAX_MONEY / 2 + 1; i < MAX_MONEY; i++)
		{
			for (int j = 0; (1 << j) <= l; j++)
			{
				probWin += prob[n][i][j];
				prob[n][i][j] = 0;
			}
		}
	}
}

int main()
{
	scanf("%i", &n);
	while (--n >= 0)
	{
		scanf("%i%i%i", &k, &m, &l);
		memset(prob, 0, sizeof(prob));
		for (int i = 0; i < 10; i++)
		{
			min_[0][i] = 999999999;
			max_[0][i] = -99999999;
		}
		prob[0][MAX_MONEY / 2][0] = 1.0;
		min_[0][0] = MAX_MONEY / 2;
		max_[0][0] = MAX_MONEY / 2 + 1;
		probWin = 0.0;
		for (int i = 1; i <= m; i++)
		{
			play(i);
		}
		printf("%.4lf\n", probWin);
	}
	return 0;
}

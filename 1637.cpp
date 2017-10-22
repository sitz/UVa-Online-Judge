#include <bits/stdc++.h>

using namespace std;

#define MAXSTATE 1953125
// 1953125 = pow(5, 9)

double dp[MAXSTATE];
int used[MAXSTATE] = {}, cases = 0;

int to_idx(char s[])
{
	int x = 0;
	switch (s[0])
	{
	case '0' ... '9':
		x = s[0] - '0';
		break;
	case 'T':
		x = 10;
		break;
	case 'J':
		x = 11;
		break;
	case 'Q':
		x = 12;
		break;
	case 'K':
		x = 13;
		break;
	case 'A':
		x = 1;
		break;
	}
	return x - 1;
}

void decode(int u, int A[])
{
	for (int i = 0; i < 9; i++)
    {
		A[i] = u % 5, u /= 5;
    }
}
int encode(int A[])
{
	int u = 0;
	for (int i = 8; i >= 0; i--)
    {
		u = u * 5 + A[i];
    }
	return u;
}

int main()
{
	char s[10];
	int pile[9][4];
	while (1)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 3; j >= 0; j--)
			{
				if (scanf("%s", s) != 1)
                {
					return 0;
                }
				pile[i][j] = to_idx(s);
			}
		}
		cases++;
		used[0] = cases, dp[0] = 1;
		int u, v, A[9];
		queue<int> Q;
		Q.push(0);
		while (!Q.empty())
		{
			u = Q.front(), Q.pop();
			decode(u, A);
			vector<int> card[13];
			for (int i = 0; i < 9; i++)
			{
				if (A[i] != 4)
                {
					card[pile[i][A[i]]].push_back(i);
                }
			}
			int comb = 0;
			for (int i = 0; i < 13; i++)
			{
				comb += card[i].size() * (card[i].size() - 1) / 2;
			}
			for (int i = 0; i < 13; i++)
			{
				for (int p = 0; p < card[i].size(); p++)
				{
					for (int q = p + 1; q < card[i].size(); q++)
					{
						A[card[i][p]]++, A[card[i][q]]++;
						v = encode(A);
						if (used[v] != cases)
                        {
							used[v] = cases; dp[v] = 0; Q.push(v);
                        }
						dp[v] += dp[u] / comb;
						A[card[i][p]]--; A[card[i][q]]--;
					}
				}
			}
		}
		if (used[MAXSTATE - 1] != cases)
        {
			used[MAXSTATE - 1] = cases; dp[MAXSTATE - 1] = 0;
        }
		printf("%.6lf\n", dp[MAXSTATE - 1]);
	}
	return 0;
}

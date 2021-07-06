#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 100;

int N1, N2;
int T1[MAXSIZE + 1], T2[MAXSIZE + 1];
int lcs[MAXSIZE + 1][MAXSIZE + 1];

void input()
{
	for (int i = 1; i <= N1; i++)
	{
		scanf("%d", T1 + i);
	}
	for (int i = 1; i <= N2; i++)
	{
		scanf("%d", T2 + i);
	}
}

void solve(int kase)
{
	int i, j;
	for (i = 0; i <= N1; i++)
	{
		lcs[i][0] = 0;
	}
	for (j = 0; j <= N2; j++)
	{
		lcs[0][j] = 0;
	}
	for (i = 1; i <= N1; i++)
		for (j = 1; j <= N2; j++)
		{
			if (T1[i] == T2[j])
			{
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else
			{
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	printf("Twin Towers #%d\n", kase);
	printf("Number of Tiles : %d\n\n", lcs[N1][N2]);
}

int main()
{
	int kase = 0;
	while (EOF != scanf("%d%d", &N1, &N2) && N1)
	{
		input();
		solve(++kase);
	}
	return 0;
}

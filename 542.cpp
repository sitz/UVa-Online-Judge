#include <bits/stdc++.h>

using namespace std;

char team[16][20];
double p[16][16], w[16][4];

void play(int round)
{
	int i, j;
	for (i = 0; i < 16; i++)
		for (j = 0; j < 16; j++)
		{
			if (i == j)
			{
				continue;
			}
			int two1 = (int)pow(2.0, round);
			int two2 = (int)pow(2.0, round + 1);
			if (i / two2 == j / two2 && i / two1 != j / two1)
			{
				w[i][round] += w[i][round - 1] * w[j][round - 1] * p[i][j];
			}
		}
}

int main()
{
	int i, j;
	for (i = 0; i < 16; i++)
	{
		scanf("%s", team[i]);
	}
	for (i = 0; i < 16; i++)
		for (j = 0; j < 16; j++)
		{
			scanf("%lf", &p[i][j]);
			p[i][j] /= 100.0;
		}
	// 1st rd
	for (i = 0; i < 16; i += 2)
	{
		w[i][0] = p[i][i + 1];
		w[i + 1][0] = p[i + 1][i];
	}
	// nxt 3 rd
	play(1);
	play(2);
	play(3);
	for (i = 0; i < 16; i++)
	{
		printf("%-10s p=%.2lf%%\n", team[i], w[i][3] * 100.0);
	}
	return 0;
}

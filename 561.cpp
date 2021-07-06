#include <bits/stdc++.h>

using namespace std;

/**
561
**/
#define MAXN 201
int N;
int P, Q, R;
char Slot[4][MAXN];
int Fre[4][30];
void CF()
{
	int i, j, s, k;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; Slot[i][j]; j++)
		{
			k = Slot[i][j] - 65;
			Fre[i][k]++;
		}
	}
}
void Cal()
{
	int i, j, a, b, c;
	double Sum = 0, d, p, q;
	CF();
	for (i = 0; i < 28; i++)
	{
		if (Fre[0][i] && Fre[1][i] && Fre[2][i])
		{
			d = (double)Fre[0][i] / P;
			p = (double)Fre[1][i] / Q;
			q = (double)Fre[2][i] / R;
			Sum += (d * p * q);
		}
	}
	printf("%.4lf\n", Sum * 34);
}
int main()
{
	int i;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d%d%d\n", &P, &Q, &R);
		for (i = 0; i < 3; i++)
		{
			scanf("%s", Slot[i]);
		}
		Cal();
		for (i = 0; i < 3; i++)
		{
			memset(Fre[i], 0, sizeof(int) * 28);
		}
	}
	return 0;
}

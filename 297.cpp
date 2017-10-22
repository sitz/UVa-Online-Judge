#include <bits/stdc++.h>

using namespace std;

/*
Quadtrees
297
*/
#define MAXN 100000
char str[MAXN + 5], F[6][MAXN + 5];
int sum, m;
void Recur(int depth, int p, int k)
{
	int i, j;
	j = p * 4 + k;
	if (F[depth][j] == 2)
	{
		return;
	}
	if (str[m] == 'e')
	{
		return;
	}
	if (str[m] == 'f')
	{
		F[depth][j] = 2;
		return;
	}
	F[depth][j] = 1;
	for (i = 0; i < 4; i++)
	{
		m++;
		Recur(depth + 1, j, i);
	}
}
void Recur1(int depth, int p, int unit, int k)
{
	int i, j;
	j = p * 4 + k;
	if (F[depth][j] == 0)
	{
		return;
	}
	if (F[depth][j] == 2)
	{
		sum += (unit * unit);
		return;
	}
	for (i = 0; i < 4; i++)
	{
		m++;
		Recur1(depth + 1, j, unit / 2, i);
	}
}
void Cal()
{
	int i, j;
	sum = m = 0;
	scanf("%s", str);
	Recur(0, 0, 0);
	m = 0;
	scanf("%s", str);
	Recur(0, 0, 0);
	Recur1(0, 0, 32, 0);
	printf("There are %d black pixels.\n", sum);
	for (i = 0; i < 6; i++)
		for (j = 0; j < MAXN; j++)
		{
			F[i][j] = 0;
		}
}
int main()
{
	int kase;
	scanf("%d", &kase);
	while (kase--)
	{
		Cal();
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

/*
Factorial Factor
884
*/
#define MAX 1005
int P[200], tp;
int F[1000002];
char sv[MAX];
void Prime_table()
{
	int i, j;
	for (i = 2; i * i <= 1000;)
	{
		for (j = i + i; j < 1000; j += i)
		{
			sv[j] = 1;
		}
		for (++i; sv[i]; i++)
			;
	}
	tp = 1;
	P[0] = 2;
	for (i = 3; i < 1000; i += 2)
	{
		if (sv[i] == 0)
		{
			P[tp++] = i;
		}
	}
}
int Times(int n)
{
	int i, c = 0;
	for (i = 0; P[i] * P[i] <= n && i < tp; i++)
	{
		if (n % P[i] == 0)
		{
			while (n % P[i] == 0)
			{
				c++;
				n /= P[i];
			}
		}
	}
	if (n > 1)
	{
		c++;
	}
	return c;
}
void Gen()
{
	int i, c = 1;
	F[2] = 1;
	for (i = 3; i <= 1000000; i++)
	{
		c += Times(i);
		F[i] = c;
	}
}
int main()
{
	int n;
	Prime_table();
	Gen();
	while (scanf("%d", &n) == 1)
	{
		printf("%d\n", F[n]);
	}
	return 0;
}

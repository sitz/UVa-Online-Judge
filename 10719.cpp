#include <bits/stdc++.h>

using namespace std;

/*
10719
Quotient Polynomial
*/
#define MAXN 10005
char input[MAXN * 20];
int P[MAXN], q[MAXN];
int N, K;
void Sep()
{
	N = 0;
	char *p;
	p = strtok(input, " ");
	while (p)
	{
		P[N++] = atoi(p);
		p = strtok(NULL, " ");
	}
}
void SolvedCase()
{
	int i, x, y, r;
	q[0] = P[0];
	for (i = 1; i + 1 < N; i++)
	{
		x = q[i - 1] * -K;
		y = P[i] - x;
		q[i] = y;
	}
	r = q[i - 1] * (-K);
	r = P[N - 1] - r;
	printf("q(x):");
	for (i = 0; i + 1 < N; i++)
	{
		printf(" %d", q[i]);
	}
	printf("\n");
	printf("r = %d\n\n", r);
}
void Special()
{
	int r;
	printf("q(x): %d\n", P[0]);
	r = P[0] * (-K);
	r = P[1] - r;
	printf("r = %d\n\n", r);
}
int main()
{
	while (gets(input))
	{
		K = atoi(input);
		gets(input);
		Sep();
		if (N > 2)
		{
			SolvedCase();
		}
		else
		{
			Special();
		}
	}
	return 0;
}

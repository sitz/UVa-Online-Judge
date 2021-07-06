#include <bits/stdc++.h>

using namespace std;

int Dis, F, L, R;

struct ss
{
	double walk, cycle;
};
ss S[22];
int N;
double Max;
int Impossible()
{
	int i;
	if (N == 1)
	{
		return 0;
	}
	for (i = 0; i + 1 < N; i++)
	{
		if (S[i].walk > S[N - 1].walk && S[i].cycle > S[N - 1].cycle)
		{
			return 1;
		}
	}
	return 0;
}
double Times(double d, double sp)
{
	double x, y, v;
	if (d == 0)
	{
		return 0;
	}
	x = 36 * d;
	y = sp * 10;
	v = x / y;
	return v;
}
void Find(double w)
{
	double c = (Dis * 1000) - w;
	double a, b, min = 100000000, d;
	int i;
	//  w *= 1000;
	//  c *= 1000;
	a = Times(w, S[N - 1].walk);
	a += Times(c, S[N - 1].cycle);
	for (i = 0; i + 1 < N; i++)
	{
		b = Times(w, S[i].walk);
		b += Times(c, S[i].cycle);
		if (b < min)
		{
			min = b;
		}
	}
	if (a <= min)
	{
		F = 1;
		d = min - a;
		if (d > Max)
		{
			Max = d;
			L = (int)w;
			R = Dis * 1000 - L;
		}
	}
}
void Cal()
{
	int d;
	double x, y;
	if (Impossible())
	{
		printf("The cheater cannot win.\n");
		return;
	}
	Max = F = 0;
	d = Dis * 1000;
	for (int i = 0; i <= d; i++)
	{
		Find(i);
	}
	if (F == 0)
	{
		printf("The cheater cannot win.\n");
		return;
	}
	printf("The cheater can win by ");
	printf("%.lf seconds with ", Max);
	x = double(L) / 1000;
	y = double(R) / 1000;
	printf("r = %.2lfkm and k = %.2lfkm.\n", x, y);
}

int main()
{
	while (scanf("%d", &Dis) == 1)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%lf%lf", &S[i].walk, &S[i].cycle);
		}
		Cal();
	}
	return 0;
}

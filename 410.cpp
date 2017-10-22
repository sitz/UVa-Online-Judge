#include <bits/stdc++.h>

using namespace std;

struct ss
{
	int a, b;
	double diff;
} sp[70];
char F[20], fg[20];
int C, S, sl, rlen, V[12], Record[20], Temp[20];
double Min, av;

void Ini(int sum)
{
	int i, j, k;
	double diff;
	sl = 0;
	av = (double)sum / C;
	for (i = 0; i < S - 1; i++)
	{
		for (j = i + 1; j < S; j++)
		{
			k = V[i] + V[j];
			diff = fabs(k - av);
			sp[sl].a = i;
			sp[sl].b = j;
			sp[sl++].diff = diff;
		}
	}
	for (i = 0; i < S; i++)
	{
		sp[sl].a = i;
		sp[sl].b = -1;
		sp[sl++].diff = fabs(V[i] - av);
	}
}
void Copy(int level)
{
	int i;
	for (i = 0; i <= level; i++)
		Record[i] = Temp[i];
	rlen = level;
}
void Recur(int level, double sum, int ind, int total)
{
	int i, t = 0, dif;
	double dum;
	Temp[level] = ind;
	if (sum > Min || level >= C)
		return;
	if (F[sp[ind].a])
		return;
	if (sp[ind].b >= 0)
		if (F[sp[ind].b])
			return;
	if (total == S)
	{
		dif = C - level - 1;
		dum = dif * av;
		if (sum + dum > Min)
			return;
		Copy(level);
		Min = sum + dum;
		return;
	}
	if (sp[ind].a >= 0)
		F[sp[ind].a] = 1;
	if (sp[ind].b >= 0)
		F[sp[ind].b] = 1;
	for (i = ind + 1; i < sl; i++)
	{
		if (sp[i].a >= 0)
			t++;
		if (sp[i].b >= 0)
			t++;
		Recur(level + 1, sum + sp[i].diff, i, total + t);
		t = 0;
	}
	F[sp[ind].a] = 0;
	if (sp[ind].b >= 0)
		F[sp[ind].b] = 0;
}
void Print()
{
	int i, k;
	for (i = 0; i <= rlen; i++)
	{
		k = Record[i];
		printf(" %d:", i);
		if (sp[k].a >= 0)
			printf(" %d", V[sp[k].a]);
		if (sp[k].b >= 0)
			printf(" %d", V[sp[k].b]);
		printf("\n");
	}
	for (i; i < C; i++)
	{
		printf(" %d:\n", i);
	}
}
void Cal()
{
	int i, t = 0;
	Min = 1000000;
	for (i = 0; i <= sl - S; i++)
	{
		if (sp[i].a >= 0)
			t++;
		if (sp[i].b >= 0)
			t++;
		Recur(0, sp[i].diff, i, t);
		t = 0;
	}
	Print();
	printf("IMBALANCE = %.5lf\n", Min);
}

int main()
{
	int i, sum, f = 1;
	while (scanf("%d%d", &C, &S) == 2)
	{
		sum = 0;
		for (i = 0; i < S; i++)
		{
			scanf("%d", &V[i]);
			sum += V[i];
		}
		Ini(sum);
		printf("Set #%d\n", f++);
		Cal();
		printf("\n");
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define maxn 1000
double P, Ind[maxn + 2];
int C, Ith;

void Gen()
{
	double p = 1 - P, t = 1;
	int i;
	Ind[0] = 1;
	for (i = 1; i <= C; i++)
	{
		t *= p;
		Ind[i] = t;
	}
}
void Cal()
{
	double u, d;
	if ((P - 0) < 1E-5)
	{
		printf("0.0000\n");
		return;
	}
	/*  if(C == 1 && Ith == 1) {
	        printf("1.0000\n");
	        return;
	    }*/
	d = 1 - (Ind[C]);
	u = P * Ind[Ith - 1];
	printf("%.4lf\n", (u / d));
}

int main()
{
	int ks;
	scanf("%d", &ks);
	while (ks--)
	{
		scanf("%d%lf%d", &C, &P, &Ith);
		Gen();
		Cal();
	}
	return 0;
}

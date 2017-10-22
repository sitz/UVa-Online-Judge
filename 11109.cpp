#include <bits/stdc++.h>

using namespace std;

int i, j, k;
double vb, vw, vr, vc, avg, amt;
int main()
{
	while (5 == scanf("%d%lf%lf%lf%lf", &k, &vb, &vw, &vr, &vc))
	{
		amt = vb + vw - vr;
		if (amt < 0)
		{
			printf("0\n");
			continue;
		}
		avg = amt / k;
		if (avg >= vc - vr)
		{
			avg = vc - vr;
		}
		if (avg >= vw - vr)
		{
			printf("%d %0.2lf", k, avg - vw + vr);
			for (i = 1; i < k; i++)
			{
				printf(" %0.2lf", avg);
			}
			printf("\n");
		}
		else
		{
			avg = vb / (k - 1);
			printf("%d 0.00", k);
			for (i = 1; i < k; i++)
			{
				printf(" %0.2lf", avg);
			}
			printf("\n");
		}
	}
}

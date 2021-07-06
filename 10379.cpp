#include <bits/stdc++.h>

using namespace std;

double cons[101], time_[101], race[101], fuel[101];
int since[101], stops[101], nstops[101];

int main()
{
	int laps, i, j, k, l;
	double lapt, laptinc, lapc, lapcinc, pt, ptinc;
	int nstops, lastop;
	while (7 == scanf("%d %lf %lf %lf %lf %lf %lf",
										&laps, &lapt, &laptinc, &lapc, &lapcinc, &pt, &ptinc))
	{
		fprintf(stdout, "%d %.3lf %.3lf %.3lf %.3lf %.3lf %.3lf\n",
						laps, lapt, laptinc, lapc, lapcinc, pt, ptinc);
		for (i = 0; i < laps; i++)
		{
			double x = (cons[i] * lapcinc + lapc) / (1 - lapcinc);
			cons[i + 1] = cons[i] + x;
			time_[i + 1] = time_[i] + lapt + laptinc * cons[i + 1];
		}
		for (i = 0; i <= laps; i++)
		{
			race[i] = time_[i];
			since[i] = i;
		}
		for (i = 1; i < laps; i++)
		{
			for (j = 1; j <= laps - i; j++)
			{
				double x = race[i] + time_[j] + pt + ptinc * cons[j];
				if (x < race[i + j])
				{
					race[i + j] = x;
					since[i + j] = j;
				}
			}
		}
		nstops = 0;
		lastop = laps;
		for (;;)
		{
			if (lastop == 0)
			{
				break;
			}
			stops[nstops] = lastop - since[lastop];
			fuel[nstops] = cons[since[lastop]];
			lastop -= since[lastop];
			if (lastop == 0)
			{
				break;
			}
			nstops++;
		}
		printf("%.3lf %.3lf %d\n", race[laps], fuel[nstops], nstops);
		for (i = nstops - 1; i >= 0; i--)
		{
			printf("%d %.3lf\n", stops[i], fuel[i]);
		}
	}
}

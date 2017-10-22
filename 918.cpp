#include <bits/stdc++.h>

using namespace std;

#define eps 1e-12
char w[16];
int main()
{
	int t, first = 1, it, i, j;
	double r, c, cr, cc, nr, nc, minc, minr, maxc, maxr, pc, pr;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s%lf%lf%lf%lf%lf%lf", w, &minc, &maxc, &pc, &minr, &maxr, &pr);
		maxc += eps, maxr += eps;
		w[13] = ' ';
		if (first)
		{
			first = 0;
		}
		else
		{
			printf("\n");
		}
		for (cc = minc, i = 0; cc <= maxc; i++, cc = minc + i * pc)
		{
			for (cr = minr, j = 0; cr <= maxr; j++, cr = minr + j * pr)
			{
				r = c = 0.0;
				for (it = 0; r * r + c * c < 4 + eps && it < 13; it++)
				{
					nr = r * r - c * c + cr;
					nc = 2 * r * c + cc;
					r = nr, c = nc;
				}
				printf("%c", w[it]);
			}
			printf("\n");
		}
	}
	return 0;
}

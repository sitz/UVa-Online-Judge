#include <bits/stdc++.h>

using namespace std;

#define min(x, y) ((x) < (y) ? (x) : (y))

double htx[6000];
#define ht (htx + 3000)

int leftx, rightx, L, R, i, j, k, ii, jj;
double rheight, lheight, rneed, lneed, need, H, vol;

int main()
{
	while (2 == scanf("%d%d", &leftx, &rightx) && leftx)
	{
		memset(htx, 0, sizeof(htx));
		vol = 0;
		ht[leftx - 2] = ht[rightx + 2] = 0x7fffffff;
		for (i = leftx; i <= rightx; i += 2)
		{
			scanf("%lf", &ht[i]);
		}
		L = -1;
		R = 1;
		while (ht[leftx] > ht[leftx + 1] && ht[rightx] > ht[rightx - 1])
		{
			H = min(ht[L], ht[R]);
			if (ht[L + 1] < H || ht[R - 1] < H)
			{
				for (i = L + 1; i <= R - 1; i += 2)
				{
					vol += 2 * (H - ht[i]);
					ht[i] = H;
				}
				continue;
			}
			if (ht[R - 1] == ht[R])
			{
				for (i = R - 1; ht[i] >= ht[i + 1]; i += 2)
					;
				for (j = i; ht[i] == ht[j]; j -= 2)
					;
				rheight = min(ht[i + 1], ht[0]);
				rheight = min(rheight, ht[j + 1]);
				rneed = (rheight - ht[i]) * (i - j);
			}
			else
			{
				rheight = rneed = 0;
			}
			if (ht[L + 1] == ht[L])
			{
				for (ii = L - 1; ht[ii] >= ht[ii - 1]; ii -= 2)
					;
				for (jj = ii; ht[ii] == ht[jj]; jj += 2)
					;
				lheight = min(ht[ii - 1], ht[0]);
				lheight = min(lheight, ht[jj - 1]);
				lneed = (lheight - ht[ii]) * (jj - ii);
			}
			else
			{
				lneed = lheight = 0;
			}
			if (rneed)
				for (k = j + 2; k <= i; k += 2)
				{
					if (lneed && lneed < rneed)
					{
						ht[k] += (rheight - ht[i]) * lneed / rneed;
					}
					else
					{
						ht[k] = rheight;
					}
				}
			if (lneed)
				for (k = jj - 2; k >= ii; k -= 2)
				{
					if (rneed && rneed < lneed)
					{
						ht[k] += (lheight - ht[ii]) * rneed / lneed;
					}
					else
					{
						ht[k] = lheight;
					}
				}
			if (lneed && rneed)
			{
				vol += 2 * min(lneed, rneed);
			}
			else
			{
				vol += (lneed + rneed);
			}
			while (ht[R + 1] == ht[R - 1])
			{
				R += 2;
			}
			while (ht[L - 1] == ht[L + 1])
			{
				L -= 2;
			}
		}
		printf("%0.0lf\n", vol);
	}
	return 0;
}

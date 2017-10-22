#include <bits/stdc++.h>

using namespace std;

// bruteforce + iterative deepening
// first rotate polygon 360 deg and locate global min/max area
// of bounding rect, then that will be the estimates
// find bounding intervals for the min/max area
// you'd need to recursively zoom into the bounding interval until
// they are accurate to 3 dp

typedef long double dbl;

#define PI ((dbl)3.1415926535897932384623832795)
dbl x[200], y[200];
int n, casen = 1;

#define PP                        \
	dbl xmax = 0;                   \
	dbl xmin = 0;                   \
	dbl ymax = 0;                   \
	dbl ymin = 0;                   \
	for (i = 0; i < n; i++)         \
	{                               \
		dbl s = sin(a);               \
		dbl c = cos(a);               \
		dbl x2 = x[i] * c - y[i] * s; \
		dbl y2 = x[i] * s + y[i] * c; \
		if (x2 < xmin)                \
			xmin = x2;                  \
		else if (x2 > xmax)           \
			xmax = x2;                  \
		if (y2 < ymin)                \
			ymin = y2;                  \
		else if (y2 > ymax)           \
			ymax = y2;                  \
	}                               \
	dbl aa = (xmax - xmin) * (ymax - ymin);

#define UPDATE       \
	if (aa > max)      \
	{                  \
		max = aa;        \
		amax = a;        \
	}                  \
	else if (aa < min) \
	{                  \
		min = aa;        \
		amin = a;        \
	}

dbl getMin(dbl min, dbl aL, dbl aR)
{
	while (1)
	{
		const dbl incre = (aR - aL) / 1000;
		dbl a = aL;
		const dbl oldmin = min;
		while (a <= aR + incre * 2)
		{
			int i;
			PP if (aa < min)
			{
				min = aa;
				aL = a - incre / 2;
				aR = a + incre / 2;
			}
			a += incre;
		}

		if (abs(min - oldmin) < 0.0000001)
		{
			return min;
		}
	}
}

dbl getMax(dbl max, dbl aL, dbl aR)
{
	while (1)
	{
		const dbl incre = (aR - aL) / 1000;
		dbl a = aL;
		const dbl oldmax = max;
		while (a <= aR + incre * 2)
		{
			int i;
			PP if (aa > max)
			{
				max = aa;
				aL = a - incre / 2;
				aR = a + incre / 2;
			}
			a += incre;
		}

		if (abs(max - oldmax) < 0.0000001)
		{
			return max;
		}
	}
}

void doit()
{
	dbl incre = PI / (1000000.0 / n);
	dbl min = DBL_MAX; // min area
	dbl max = 0;			 // max area

	dbl a = 0;										 // cur angle
	dbl amin = 0;									 // angle related to min area
	dbl amax = 0;									 // angle related to max area
	dbl stop = 2 * PI + incre * 2; // overrun a little to be safe
	int i, j;

	// estimate global min and max area
	while (a <= stop)
	{
		PP UPDATE a += incre;
	}

	// find interval bound
	incre /= (1 << 12);
	dbl aR;
	a = amin;
	while (1)
	{
		a += incre;
		PP if (aa > min) { break; }
	}
	aR = a;

	a = amin;
	while (1)
	{
		a -= incre;
		PP if (aa > min) { break; }
	}

	min = getMin(min, a, aR);

	printf("Gift %d\n", casen);
	printf("Minimum area = %.3Lf\n", min);

	// find interval bound
	a = amax;
	while (1)
	{
		a += incre;
		PP if (aa < max) { break; }
	}
	aR = a;

	a = amax;
	while (1)
	{
		a -= incre;
		PP if (aa < max) { break; }
	}

	max = getMax(max, a, aR);

	printf("Maximum area = %.3Lf\n\n", max);
	casen++;
}

int main()
{
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			break;
		}
		int i, j, k, xx0, yy0, xx, yy;
		scanf("%d%d", &xx0, &yy0);
		for (i = 1; i < n; i++)
		{
			scanf("%d%d", &xx, &yy);
			x[i] = (dbl)(xx - xx0);
			y[i] = (dbl)(yy - yy0);
		}
		x[0] = y[0] = 0;
		doit();
	}
	return 0;
}

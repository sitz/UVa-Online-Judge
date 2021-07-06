#include <bits/stdc++.h>

using namespace std;

// @ http://acmph.blogspot.sg/2012/12/uva-10839-curse-of-barbosa.html
// DP
// observe the problem as a graph with 3 nodes, if self loop was allowed in this problem then it would become a matrix multiplication problem, but now we have to count special paths, dp[x][y][z][node] means how many different roads can be made which city 1 is seen x times, city 2 is seen y times, city 3 is seen z times and we are at city 'node'. how to update this?
// dp[x][y][z][node] += dp[x-1][y][z][1] if node != 1
// dp[x][y][z][node] += dp[x][y-1][z][2] if node != 2
// dp[x][y][z][node] += dp[x][y][z-2][3] if node != 3
// we know the basic case dp[0][0][0][1] = 1, in this way we can update our table.
// each time we read n, output = dp[n/3][n/3][n/3][1] is the number of ways we can start from 1 and end at 1, but output counts some paths and it's reverse, some paths not all paths, palindrome paths are counted just once, their reverse is not counted, so if we add the number of palindrome paths, we can divide that number by two.
// how to add palindrome paths? if n is even then there is no palindrome path, but if n is odd,  m = (n+1)/2, and we calculate dp[m/3][m/3][m/3][1] and add it to dp[n/3][n/3][n/3][1], the result would be (dp[m/3][m/3][m/3][1] + dp[n/3][n/3][n/3][1] ) / 2. (need biginteger)

#define NLIMBS 6
#define FVAL (&ftab[s][a][b][c])

typedef unsigned long UL;
typedef unsigned long long ULL;

typedef struct mp {UL d[NLIMBS];} mp_t;

static mp_t c_zero, c_one;

static void mp_add(mp_t *z, const mp_t *x, const mp_t *y)
{
	register int i;
	register ULL c;
	for (i = 0, c = 0; i < NLIMBS; i++, c >>= 32)
	{
		c += (ULL)x->d[i] + (ULL)y->d[i];
		z->d[i] = (UL)(c);
	}
}

static void mp_sub(mp_t *z, const mp_t *x, const mp_t *y)
{
	register int i;
	register ULL c;
	for (i = 0, c = 1; i < NLIMBS; i++, c >>= 32)
	{
		c += (ULL)x->d[i] + (((ULL)y->d[i]) ^ 0xFFFFFFFFULL);
		z->d[i] = (UL)(c);
	}
}

static void mp_set(mp_t *z, const mp_t *x)
{
	register int i;
	for (i = 0; i < NLIMBS; i++)
	{
		z->d[i] = x->d[i];
	}
}

static void mp_load(mp_t *x, int n)
{
	int i;
	for (x->d[0] = n, i = 1; i < NLIMBS; i++)
	{
		x->d[i] = 0;
	}
}

static unsigned mp_div1(mp_t *x, unsigned d)
{
	register int i;
	register ULL c;
	for (c = 0, i = NLIMBS - 1; i >= 0; i--)
	{
		c = (c << 32) | (ULL)x->d[i];
		x->d[i] = (UL)(c / (ULL)d);
		c %= (ULL)d;
	}
	return c;
}

static char *mp_print(mp_t *x)
{
	static mp_t t;
	static char buf1[1024], buf2[1024];
	int i, j;
	mp_set(&t, x);
	for (i = 0;;)
	{
		buf1[i++] = mp_div1(&t, 10) + '0';
		for (j = 0; j < NLIMBS; j++)
			if (t.d[j] != 0)
			{
				break;
			}
		if (j >= NLIMBS)
		{
			break;
		}
	}
	for (j = 0; i-- > 0;)
	{
		buf2[j++] = buf1[i];
	}
	buf2[j] = '\0';
	return buf2;
}

// //

#define MAXM 40
#define GVAL (&gtab[s][a][b][c])

static char gtab_u[4][MAXM][MAXM][MAXM], ftab_u[4][MAXM][MAXM][MAXM];
static mp_t gtab[4][MAXM][MAXM][MAXM], ftab[4][MAXM][MAXM][MAXM];

static mp_t *g(int s, int a, int b, int c)
{
	if (a < 0 || b < 0 || c < 0)
	{
		return &c_zero;
	}
	if (gtab_u[s][a][b][c])
	{
		return GVAL;
	}
	gtab_u[s][a][b][c] = 1;
	if ((a + b + c) == 1)
	{
		if ((s == 1 && a == 1) || (s == 2 && b == 1) ||
				(s == 3 && c == 1))
		{
			mp_load(GVAL, 0);
			return GVAL;
		}
		mp_load(GVAL, 1);
		return GVAL;
	}
	if (s == 1)
	{
		mp_add(GVAL, g(2, a, b - 2, c), g(3, a, b, c - 2));
		return GVAL;
	}
	else if (s == 2)
	{
		mp_add(GVAL, g(1, a - 2, b, c), g(3, a, b, c - 2));
		return GVAL;
	}
	else
	{
		mp_add(GVAL, g(1, a - 2, b, c), g(2, a, b - 2, c));
		return GVAL;
	}
}

static mp_t *f(int s, int a, int b, int c)
{
	if (a < 0 || b < 0 || c < 0)
	{
		return &c_zero;
	}
	if (ftab_u[s][a][b][c])
	{
		return FVAL;
	}
	ftab_u[s][a][b][c] = 1;
	if ((a + b + c) <= 0)
	{
		mp_load(FVAL, 0);
		return FVAL;
	}
	if ((a + b + c) == 1)
	{
		if (a == 1 && s != 1)
		{
			mp_load(FVAL, 1);
		}
		else
		{
			mp_load(FVAL, 0);
		}
		return FVAL;
	}
	if (s == 1)
	{
		mp_add(FVAL, f(2, a, b - 1, c), f(3, a, b, c - 1));
	}
	else if (s == 2)
	{
		mp_add(FVAL, f(1, a - 1, b, c), f(3, a, b, c - 1));
	}
	else
	{
		mp_add(FVAL, f(1, a - 1, b, c), f(2, a, b - 1, c));
	}
	return FVAL;
}

int main()
{
	int n, m, c, t;
	mp_t *fv, *gv, u;
	mp_load(&c_zero, 0);
	mp_load(&c_one, 1);
	memset(gtab_u, 0, sizeof(gtab_u));
	memset(ftab_u, 0, sizeof(ftab_u));
	scanf("%d", &t);
	for (c = 1; c <= t && scanf("%d", &n) == 1; c++)
	{
		if (n == 1)
		{
			printf("Case %d: 1\n", c);
			continue;
		}
		m = (n - 1) / 3;
		fv = f(1, m, m, m);
		gv = g(1, m - 1, m, m);
		mp_sub(&u, fv, gv);
		mp_div1(&u, 2);
		mp_add(&u, &u, gv);
		printf("Case %d: %s\n", c, mp_print(&u));
	}
	return 0;
}

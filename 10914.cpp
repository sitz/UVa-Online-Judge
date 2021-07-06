#include <bits/stdc++.h>

using namespace std;

/*
10914
Abundance and Perfect Number
*/
#define maxn 5000000
#define limit 10000000
typedef long long ss;
char sv[maxn + 2];
int P[348515], tp;
struct xx
{
	int pos;
	ss abn;
};
xx A[737059];
ss ta;
int com(const void *a, const void *b)
{
	xx *x = (xx *)a;
	xx *y = (xx *)b;
	return x->pos - y->pos;
}
void PrimeTable()
{
	int i, j;
	tp = 1;
	for (i = 2; i * i < maxn;)
	{
		for (j = i + i; j <= maxn; j += i)
		{
			sv[j] = 1;
		}
		for (++i; sv[i]; i++)
			;
	}
	P[0] = 2;
	for (i = 3; i <= maxn; i += 2)
	{
		if (!sv[i])
		{
			P[tp++] = i;
		}
	}
}
ss Abun(ss two, ss prim, ss pos)
{
	ss fact, d, k;
	fact = (prim * prim) - 1;
	d = prim - 1;
	fact = fact / d;
	k = fact * two - 2 * pos;
	return k;
}
void Gen()
{
	ss i, d = 1, j, k = 0, p = 1, pro;
	for (i = 1; i; i++)
	{
		p = p * 2 + 1;
		d *= 2;
		if (d >= limit)
		{
			break;
		}
		for (j = 1; j < tp; j++)
		{
			pro = P[j] * d;
			if (pro > limit)
			{
				break;
			}
			A[k].pos = (int)pro;
			A[k].abn = Abun(p, P[j], pro);
			k++;
		}
	}
	ta = k;
	qsort(A, (int)ta, sizeof(xx), com);
	for (i = 1; i < ta; i++)
	{
		A[i].abn += A[i - 1].abn;
	}
}
ss BS(ss key)
{
	ss lo = 0, up = ta - 1;
	ss mid = (lo + up) / 2;
	while (lo < up)
	{
		if (A[mid].pos > key)
		{
			if (A[mid - 1].pos <= key)
			{
				return A[mid - 1].abn;
			}
			up = mid - 1;
		}
		else if (A[mid].pos < key)
		{
			if (A[mid + 1].pos == key)
			{
				return A[mid + 1].abn;
			}
			if (A[mid + 1].pos > key)
			{
				return A[mid].abn;
			}
			lo = mid + 1;
		}
		else
		{
			return A[mid].abn;
		}
		mid = (lo + up) / 2;
	}
	return A[mid].abn;
}
void Cal(ss n)
{
	if (n <= 5)
	{
		printf("0\n");
		return;
	}
	printf("%lld\n", BS(n));
}
int main()
{
	ss n;
	PrimeTable();
	Gen();
	while (scanf("%lld", &n) && n)
	{
		printf("%lld ", n);
		Cal(n);
	}
	return 0;
}

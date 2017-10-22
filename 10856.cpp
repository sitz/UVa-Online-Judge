#include <bits/stdc++.h>

using namespace std;

/*
10856
*/
#define mx 3000000
int P[mx + 2], tp;
char Fg[mx + 2];
typedef long long ss;
void Table()
{
	ss i, j, k;
	for (i = 2; i <= mx;)
	{
		P[i]++;
		for (j = i + i; j <= mx; j += i)
		{
			Fg[j] = 1;
			P[j]++;
		}
		for (j = i * i; j <= mx; j *= i)
		{
			P[j]++;
			for (k = j + j; k <= mx; k += j)
			{
				P[k]++;
			}
		}
		for (++i; Fg[i]; i++)
			;
	}
	for (i = 2; i <= mx; i++)
	{
		P[i] += P[i - 1];
	}
}
int Count(int n)
{
	int i, p = 0;
	if (Fg[n] > 0)
	{
		return Fg[n];
	}
	for (i = 0; P[i] <= n && i < tp; i++)
	{
		for (int j = P[i]; j <= n; j *= P[i])
		{
			p += n / j;
		}
	}
	Fg[n] = p;
	return p;
}
int BinarySearch(int key)
{
	int lo = 2, up = mx, mid, fac, lfac, rfac;
	mid = (lo + up) / 2;
	if (key == 0)
	{
		return 0;
	}
	if (key == 1)
	{
		return 2;
	}
	while (lo < up)
	{
		fac = P[mid];
		if (fac > key)
		{
			up = mid - 1;
		}
		else if (fac < key)
		{
			lo = mid + 1;
		}
		else
		{
			return mid;
		}
		mid = (lo + up) / 2;
	}
	fac = P[mid];
	if (fac != key)
	{
		return -1;
	}
	return mid;
}
int main()
{
	int n, k = 1, d;
	Table();
	while (scanf("%d", &n) && n >= 0)
	{
		d = BinarySearch(n);
		if (d < 0)
		{
			printf("Case %d: Not possible.\n", k++);
		}
		else
		{
			printf("Case %d: %d!\n", k++, d);
		}
	}
	return 0;
}

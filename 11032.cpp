#include <bits/stdc++.h>

using namespace std;

/*
11032
*/
#define maxn 10000001
#define maxx 977788
#define MAX(a, b) (a > b ? a : b)
char Fg[maxn];
int A[maxx + 1];
int pre, ind, pre1;
int com(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int Sod(int n)
{
	int d = 0, k;
	if (n % 10)
	{
		k = pre + n % 10;
		return k;
	}
	while (n)
	{
		d += n % 10;
		n /= 10;
	}
	pre = d;
	return d;
}
void Gen()
{
	int i, d, k;
	pre = 0;
	ind = 0;
	k = 1;
	for (i = 1; i < maxn; i++)
	{
		d = Sod(i) + i;
		if (d >= maxn)
		{
			continue;
		}
		Fg[d] = 1;
	}
	for (i = 1; i < maxn; i++)
		if (Fg[i] == 0)
		{
			A[ind++] = i;
		}
}
int Lower(int key)
{
	int lo = 0, up = ind - 1, mid;
	mid = (lo + up) / 2;
	if (key <= A[lo])
	{
		return 0;
	}
	if (key > A[up])
	{
		return -1;
	}
	while (1)
	{
		if (A[mid] > key)
		{
			if (A[mid - 1] < key)
			{
				return mid;
			}
			if (A[mid - 1] == key)
			{
				return mid - 1;
			}
			up = mid - 1;
		}
		else if (A[mid] < key)
		{
			if (A[mid + 1] >= key)
			{
				return mid + 1;
			}
			lo = mid + 1;
		}
		else
		{
			return mid;
		}
		mid = (lo + up) / 2;
	}
	return -1;
}
int Upper(int key)
{
	int lo = 0, up = ind - 1, mid;
	mid = (lo + up) / 2;
	if (key < A[lo])
	{
		return -1;
	}
	if (key >= A[up])
	{
		return up;
	}
	while (1)
	{
		if (A[mid] > key)
		{
			if (A[mid - 1] <= key)
			{
				return mid - 1;
			}
			up = mid - 1;
		}
		else if (A[mid] < key)
		{
			if (A[mid + 1] == key)
			{
				return mid + 1;
			}
			if (A[mid + 1] > key)
			{
				return mid;
			}
			lo = mid + 1;
		}
		else
		{
			return mid;
		}
		mid = (lo + up) / 2;
	}
	return -1;
}
int SS(int n)
{
	int d = 0;
	while (n)
	{
		d += n % 10;
		n /= 10;
	}
	return d;
}
void F1(int n)
{
	int i, *d;
	d = (int *)bsearch(&n, A, ind, sizeof(int), com);
	if (d)
	{
		printf("-1\n");
		return;
	}
	for (i = MAX(1, n - 100); i <= n; i++)
	{
		if (i + SS(i) == n)
		{
			printf("%d\n", i);
			return;
		}
	}
}
void F2(int n, int m)
{
	int l, u;
	l = Lower(n);
	u = Upper(m);
	if (l < 0 || u < 0)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", u - l + 1);
	}
}
int main()
{
	char ss[100];
	int d, n, m, ts, k = 1;
	Gen();
	gets(ss);
	sscanf(ss, "%d", &ts);
	while (ts--)
	{
		gets(ss);
		d = sscanf(ss, "%d%d", &n, &m);
		printf("Case %d: ", k++);
		if (d == 1)
		{
			F1(n);
		}
		else
		{
			F2(n, m);
		}
	}
	return 0;
}

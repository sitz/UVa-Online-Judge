#include <bits/stdc++.h>

using namespace std;

struct data
{
	int i;
	long long int mod;
} arr[65536];

bool flag;
long long int P, B, N, L, m;

long long int mods(long long int base, long long int exp, long long int P)
{
	if (exp == 1)
	{
		return (long long int)(base % P);
	}
	else if (exp == 0)
	{
		return (long long int)1;
	}
	else if (exp % 2)
	{
		long long int t = mods(base, exp - 1, P);
		return (long long int)((t * base) % P);
	}
	else
	{
		long long int t = mods(base, exp / 2, P);
		return (long long int)((t * t) % P);
	}
}

int compare(const void *a, const void *b)
{
	return (*(data *)a).mod - (*(data *)b).mod;
}

// binary search
int binarysearch(long long int key, int left, int right)
{
	long long int k;
	int l, mid = (left + right) / 2, j;
	while (left <= right)
	{
		if (arr[mid].mod == key)
		{
			k = arr[mid].i;
			l = mid;
			for (j = mid - 1; arr[j].mod == key; j--)
				if (arr[j].i < k)
				{
					k = arr[j].i;
					l = j;
				}
			for (j = mid + 1; arr[j].mod == key; j++)
				if (arr[j].i < k)
				{
					k = arr[j].i;
					l = j;
				}
			return l;
		}
		else if (arr[mid].mod < key)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
		mid = (left + right) / 2;
	}
	return -1;
}

int main()
{
	int i, j;
	long long int tt;
	while (scanf("%lld%lld%lld", &P, &B, &N) == 3)
	{
		m = (int)sqrt(P - 1);
		if (m == 1)
		{
			m = P;
		}
		for (i = 0; i < m; i++)
		{
			arr[i].i = i;
			arr[i].mod = mods(B, m * i, P);
		}
		qsort(arr, m, sizeof(data), compare);
		unsigned long k = 1000000000UL;
		for (j = 0; j < m; j++)
		{
			tt = (long long int)((N * mods(B, P - 1 - j, P))) % P;
			int t = binarysearch(tt, 0, m - 1);
			if (t != -1)
			{
				if ((m * arr[t].i + j) % (P - 1) < k)
				{
					k = (m * arr[t].i + j) % (P - 1);
				}
				flag = false;
			}
		}

		if (flag || k == 1000000000)
			printf("no solution\n");
		else
			printf("%lu\n", k);
	}
	return 0;
}
